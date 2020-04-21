#include <iostream>
#pragma once

using namespace std;

template<typename T>
class TreasureMap 
{
public:

	//Default constructor: set total_steps and current_step to 0, max_steps to 10, and initialize steps to an array of 10 elements.
	TreasureMap()
	{
		current_step = 0;
		total_steps = 0;
		max_steps = 10;

		steps = new T[max_steps];
	}

	//Overloaded constructor: TreasureMap(int max_steps) sets the max_steps, and initialize steps array to max_steps.
	TreasureMap(int max_steps)
	{
		current_step = 0;
		total_steps = 0;
		this->max_steps = max_steps;

		steps = new T[max_steps];
	}

	//Function getSteps() returns the dynamic array T.
	T* getSteps()
	{
		return steps;
	}

	//Function getCurrentStep() returns the current_step.
	int getCurrentStep()
	{
		return current_step;
	}

	//Function getTotalSteps() returns the total_steps.
	int getTotalSteps()
	{
		return total_steps;
	}

	/*
	 *Function addStep(): a void function that takes in a T element, add it to steps and increment total_steps. 
	 *If total_steps is equal to max_steps, show this messageand don't add.
	 */
	void addStep(T add)
	{
		if (total_steps == max_steps)
		{
			cout << "Cannot add more steps, TreasureMap is full" << endl;
		}
		else
		{
			steps[total_steps] = add;
			total_steps++;
		}
	}
	/*
	 *Function removeStep(): a void function that takes in an int index, 
	 *and remove the element in steps at that index(make sure to decrement total_steps).
     */
	void removeStep(int index)
	{
		if ((index <= total_steps - 1) && (index >= 0))
		{
			for (int i = index; i < total_steps - 1; i++)
			{
				steps[i] = steps[i + 1];
			}

			steps[total_steps - 1] = nullptr;
		}
	}

	/*
	 *Function nextStep(): a void function that prints this message and then increment the current_step:
	 *Going from <current element> to <next element>
	 *Where current element is the T element at current_step index of steps and next element is current_step + 1. 
	 *
	 *If current_step is already the last step, print this message instead:
	 *Cannot goto next step, treasure has already been found!

	 *If after incrementing current_step and reaching the last step, print:
	 *Congratulations, you have found the treasure!
	 */
	void nextStep()
	{
		if (current_step == total_steps)
		{
			cout << "Cannot goto next step, treasure has already been found!" << endl;
		}
		else
		{
			cout << "Going from " << steps[current_step] << " to " << step[current_step + 1] << endl;
			current_step++;

			if (current_step == total_steps)
			{
				cout << "Congratulations, you have found the treasure!" << endl;
			}
		}
	}

	/*
	 *Function backtrack(): a void function that prints this message and then decrement the current_step:
	 *Backtracking from <current element> to <previous element>
	 *Where current element is the T element at current_step index of steps and previous element is current_step - 1.
	 *
	 *If current_step is already the last step, print this message instead :
	 *Cannot backtrack, you're at the very first step!
	 */
	void backtrack()
	{
		if (current_step == 0)
		{
			cout << "Cannot backtrack, you're at the very first step!" << endl;
		}
		else
		{
			cout << "Backtracking from " << steps[current_step] " to " steps[current_step - 1] << endl;
			current_step--;
		}
	}

	/*
	 *Overload the + operator, if the total_steps don't match then return a blank map (made using the default constructor). 
	 *Else make a new TreasureMap and each step in the new map is the addition of map 1's step with map 2's step. 
	 *For example, given map1 with steps 1, 2, 3 and map2 with steps 1,3,4, map3 = map1 + map2. map3's steps will be 2, 5, 7.
	 */
	TreasureMap operator+(const TreasureMap& other)
	{
		TreasureMap newMap;

		if (total_steps != other.total_steps)
		{
			return newMap;
		}
		else
		{
			for (int i = 0; i < total_steps; i++)
			{
				newMap.steps[i] = steps[i] + other.steps[i];
			}
		}

		return newMap;
	}

	//Overload the == operator, returns true if the total_steps match, and each element in steps is equal to each other. Return false otherwise
	bool operator==(const TreasureMap& other)
	{
		if (total_steps == other.total_steps)
		{
			for (int i = 0; i < total_steps; i++)
			{
				if (steps[i] != other.steps[i])
				{
					return false;
				}
				return true;
			}
		}
		else
		{
			return false;
		}
	}

private:

	T* steps;
	int current_step;
	int total_steps;
	int max_steps;

};