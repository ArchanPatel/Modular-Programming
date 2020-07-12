//*****************************************************************************
//  Student Name: Archan Patel
//  Student Number:  20834719 
//  SYDE 121 Lab: 4 Assignment: 2
//  Filename: lab04_02
//  I hereby declare that this code, submitted for credit for the course
//  SYDE121, is a product of my own efforts.  This coded solution has
//  not been plagiarized from other sources and has not been knowingly
//  plagiarized by others.
//  Project:  Vector manipulation
//  Purpose:  Allow user to input elements and then output specific stats
//  Date:  Monday, October 14, 2019
//*****************************************************************************
	
/*Test scenarios: - searched up population standard deviation values online and matched the inputs onto code
				  - calculated the mean manually and compared to program's output*/

//libraries
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;

void sort (vector<double> nums);
//purpose: to get the array of 20 numbers and sort from smallest to largest
//input: the vector to sort
//output: the sorted vector

void replace (vector<double> nums);
//purpose: to modify specific elements of the vector
//input: vector to modify
//output: the modifed vector

//main
int main()
{
	//variable declaration
	vector <double> nums; //to hold all contents of user input
	bool again = true; //whether to loop again
	int size; //holds the size of the vector after all user inputs
	string holder; //to ensure that 'd' can be input
	double d_holder; //holds the double after sonverted from string
	
	//STEP 1: obtain all the elements of the vector (could be more than 20)
	while (again)
	{
		cout << "input a double, input 'd' when finished: ";
		cin >> holder; 
		if (holder == "d") //check if they inputted 'd'
		{
			again = false;
		}
		else
		{
			d_holder = atof(holder.c_str()); //convert the string to a double
			
			//check if the input is within the range
			if (d_holder < 21.0) 
			{
				nums.push_back(d_holder); //add element to a new indew created at the end
			}
			else
				cout << "invalid entry\n";
		}
	}
	
	//STEP 2: delete all elements outside the first 20 and modify
	if (nums.size() > 20)
	{
		size = nums.size();
		for (int i = 0; i < (size - 20); i++)
		{
			nums.pop_back();
		}
	}
	
	cout << "\n";
	
	//STEP 3: output the calculations
	sort(nums); //sort the vector
	
	replace(nums); //see if any replacements need to be made
	
	//STEP 4: terminate
	return 0; 
}

//function definition
void replace (vector<double> nums)
{
	//variable declaration
	bool again = true; //whether to loop again
	string holder; //holds input
	double location; //index of vector
	double new_num; //the number as double
		
	//check for modifications
	while (again)
	{
		cout << "\ninput a valid location to modify (input 'q' to exit program): ";
		cin >> holder; //get location
		location = atof(holder.c_str()); //convert location to double
		if (holder == "q") //check whether to loop again
		{
			again = false;
		}
		else if (location > 0 && location < 21) //check bounds of input
		{
			cout << "input the new number: ";
			cin >> new_num;
			
			//modify the vector at the appropriate location with the appropriate number
			if (new_num > 0 && new_num < 21)
			{
				nums.at(location - 1) = new_num;
			}
			else 
			{
				cout << "\ninvalid entry";
			}
		}
	}
	sort (nums); //sort vector again and display new max, min, mean, psd
}

void sort (vector<double> nums)
{
    bool swap = true; //to see whether the sorting is complete
    double sum = 0; //used to find sum of all elements
    double mean = 0; //stores mean of all elements
    double psd = 0; //stores the population standard deviation
    double psd_sum = 0; //stores sum of a part in psd calculation
    
    while(swap)
    {
        swap = false; //to ensure the loop stops after sorting complete
        for (int i = 0; i < nums.size()-1; i++)
        {
        	//if element after the current one is bigger, swap
            if (nums[i]>nums[i+1] )
            {
                nums[i] += nums[i+1];
                nums[i+1] = nums[i] - nums[i+1];
                nums[i] -=nums[i+1];
                swap = true;
            }
        }
    }
    
    //output the max and min
    cout << "\nMax value: " << nums.at(nums.size()-1);
    cout << "\nMin value: " << nums.at(0);
    
    //calculate the mean and output it
    for (int i = 0; i < nums.size(); i++) 
	{
		sum += nums.at(i);
	}
	mean = sum/nums.size();
	cout << "\nMean value: " << mean;
	
	//calculate the psd and output it
	for (int i = 0; i < nums.size(); i++)
	{
		psd_sum += pow((nums.at(i) - mean), 2);
	}
	psd = pow((psd_sum/nums.size()),0.5);
	cout << "\nPopulation Standard Deviation value: " << psd;
	cout << "\n";
}


