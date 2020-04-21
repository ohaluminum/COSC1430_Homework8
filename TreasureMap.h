#include <iostream>
#pragma once

template<typename T>
class TreasureMap 
{
public:

	//Default constructor: set total_steps and current_step to 0, max_steps to 10, and initialize steps to an array of 10 elements.
	TreasureMap<t>::TreasureMap()
	{
		current_step = 0;
		total_steps = 0;
		max_steps = 10;

		steps = new T[max_steps];
	}

	//Overloaded constructor: TreasureMap(int max_steps) sets the max_steps, and initialize steps array to max_steps.
	TreasureMap<T>::TreasureMap(int max_steps)
	{
		current_step = 0;
		total_steps = 0;
		this->max_steps = max_steps;

		steps = new T[max_steps];
	}

	//Function getSteps() returns the dynamic array T.
	T* TreasureMap<T>::getSteps()
	{
		return steps;
	}

	//Function getCurrentStep() returns the current_step.
	int TreasureMap<T>::getCurrentStep()
	{
		return current_step;
	}

	//Function getTotalSteps() returns the total_steps.
	int TreasureMap<T>::getTotalSteps()
	{
		return total_steps;
	}

	/*
	 *Function addStep() a void function that takes in a T element, add it to steps and increment total_steps. 
	 *If total_steps is equal to max_steps, show this messageand don't add.
	 */
	void TreasureMap<T>::addStep(T add)
	{
		if (total_steps == max_steps)
		{
			cout << "Cannot add more steps, TreasureMap is full." << endl;
		}
		else
		{
			steps[total_steps] = add;
			total_steps++;
		}
	}

private:

	T* steps;
	int current_step;
	int total_steps;
	int max_steps;

};

