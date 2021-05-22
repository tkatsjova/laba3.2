
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "field.h"
#include "horse_move.h"
#include "position.h"

using namespace std;

bool move(field current_field, vector<horse_move*> moves, position current_position, map<int, position>& positions, int stack_size, int& calls_number);
bool validate_input(string text, int& x, int& y, bool flag);

int main()
{
	int x;
	int y;

	string input_field_data = "Enter the size of the field separated by commas: ";
	validate_input(input_field_data, x, y, false);
	const field current_field(x, y);

	string input_position_data = "Enter the original position  separated by commas: ";
	validate_input(input_position_data, x, y, false);
	position current_position(x - 1, y - 1);


	vector<horse_move*> moves;
	map<int, position> positions;
	do
	{
		string input_move_data = "Enter the possible moves separated by commas and empty string after the last one: ";
		if (validate_input(input_move_data, x, y, true))
			break;

		moves.push_back(new horse_move(x, y));
	} while (true);

	int calls_nubmber = 0;
	
	if (move(current_field, moves, current_position, positions, 0, calls_nubmber))
	{
		cout << "Moves to go through the whole board: " << endl;
		for (auto pair : positions)
		{
			cout << pair.first << " -> " << pair.second.get_x() + 1 << "," << pair.second.get_y() + 1 << endl;
		}
	}
	else
	{
		cout << "There is no solution for the entered data!";
	}
}

bool move(field current_field, vector<horse_move*> moves, position current_position, map<int, position>& positions, int stack_size, int& calls_number)
{
	stack_size++;
	calls_number++;
	cout << "The sequence number of the function call: " << to_string(calls_number) << endl;
	cout << "The stack depth of the function call: " << to_string(stack_size) << endl;

	cout << "The value of the changing argument: " << to_string(current_position.get_x()) << "," << to_string(current_position.get_y()) << endl;
	if (current_field.all_true())
		return true;
	if (!current_field.success_move(current_position))
		return false;
	positions[stack_size] = current_position;

	cout << "Current field state: " << endl;
	current_field.print();

	for (int i = 0; i < moves.size(); i++)
	{
		int x = current_position.get_x() + moves[i]->get_x();
		int y = current_position.get_y() + moves[i]->get_y();
		position new_position(x, y);
		if (move(current_field, moves, new_position, positions, stack_size, calls_number))
		{
			cout << "Function result: TRUE" << endl;
			return true;
		}

	}

	current_field.clear_position(current_position);
	positions.erase(stack_size);

	cout << "Function result: FALSE" << endl;
	return false;
}



bool validate_input(string text, int& x, int& y, bool flag)
{
	bool parsing_success = false;
	string current_input;
	do
	{
		try
		{
			cout << text;
			getline(cin, current_input);
			if (current_input == "" && flag)
				return true;
			std::stringstream   lineStream;
			lineStream << current_input;
			string number;
			std::getline(lineStream, number, ',');
			x = stoi(number);
			std::getline(lineStream, number, ',');
			y = stoi(number);
			parsing_success = true;
		}
		catch (...)
		{
			cout << "PARSING ERROR!" << endl;
			parsing_success = false;
		}
	} while (!parsing_success);

	return false;
}
