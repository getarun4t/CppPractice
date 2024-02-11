#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

class Singleton {
public:
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton operator = (const Singleton&) = delete;
	Singleton operator = (Singleton&&) = delete;

	Singleton() {
		std::cout << "Initializing singleton" << std::endl;
	}
};

Singleton& get_singleton();

#endif