/*
 * Singleton.h
 *
 *  Created on: 10 сент. 2021 г.
 *      Author: User
 */

#ifndef INC_SINGLETON_HPP_
#define INC_SINGLETON_HPP_
template <class T>
class Singleton{
private:
	static T* m_instance;
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);
	static void create()
	{
		m_instance = new T;
	}
protected:
	Singleton() {}
public:
	virtual ~Singleton() {}
	static T* instance()
	{
		if (not m_instance)
		{
			create();
		}
		return m_instance;
	}
};
template <class T>
T* Singleton<T>::m_instance = 0;
#endif /* INC_SINGLETON_HPP_ */

