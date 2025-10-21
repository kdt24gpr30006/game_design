#pragma once
#include <stack>
#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class ObjectPool;

template<typename T>
class PoolHandle
{
	T* obj;
	ObjectPool<T>* pool;
	friend class ObjectPool<T>;
	explicit PoolHandle(T* argObj, ObjectPool<T>* argPool)
		: obj(argObj), pool(argPool) {
	}

public:

	// �R�s�[�֎~
	PoolHandle(const PoolHandle&) = delete;
	// ���[�u�\
	PoolHandle(PoolHandle&& other) noexcept
		: obj(other.obj), pool(other.pool)
	{
		other.obj = nullptr;
		other.pool = nullptr;
	}
	// �f�X�g���N�^�Ŏ����J��
	~PoolHandle()
	{
		if (obj && pool)
		{
			pool->Release(obj);
		}
	}
	// �A�N�Z�X���Z�q
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

template <typename T>
class ObjectPool
{
	std::vector<std::unique_ptr<T>> objects;
	std::stack<T*> free;
	void Release(T* argObj) { free.push(argObj); }
	friend class PoolHandle<T>;

public:

	explicit ObjectPool(size_t capacity)
	{
		objects.reserve(capacity);
		for (size_t i = 0; i < capacity; ++i)
		{
			objects.emplace_back(std::make_unique<T>());
			free.push(objects.back().get());
		}
	}

	PoolHandle<T> Acquire()
	{
		if (free.empty())
		{
			throw std::runtime_error("empty");
		}
		T* obj = free.top();
		free.pop();
		return PoolHandle<T>(obj, this);
	}
};