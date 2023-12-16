#include "EdNN.h"
#include <Windows.h>
#include <iostream>



double EdNN::act_func_relu(double x)
{
	return max(0, x);
}
double EdNN::act_func_relu_differential(double x)
{
	return (x > 0) ? 1 : 0;
}



EdNN::EdNN(int count_neurons)
{
	std::vector<double> tempVectorNeuron(count_neurons, 0);
	neurons.push_back(std::move(tempVectorNeuron));

	layers_count = 1;

	act_functions.push_back(EdNN::functions::NOTHING);
}

EdNN::~EdNN()
{

}

void EdNN::addLayer(int count_neurons, EdNN::functions act_func)
{
	std::vector<double> tempVectorNeuron(count_neurons, 0);
	neurons.push_back(tempVectorNeuron);

	++layers_count;

	std::vector<std::vector<double>> tempVectorWeights(neurons[layers_count - 2].size(), tempVectorNeuron);
	weights.push_back(tempVectorWeights);

	++weights_count;

	act_functions.push_back(act_func);
}

void EdNN::setNeuronValue(int layer, int index_neuron, double value)
{
	if (layer > layers_count - 1 || layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "setNeuronValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else if (neurons[layer].size() - 1 < index_neuron || index_neuron < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid index in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "setNeuronValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		neurons[layer][index_neuron] = value;
	}
}
void EdNN::setWeightsValue(int weights_layer, int index_neuron, int index_weights, double value)
{
	if (weights_layer > weights_count - 1 || weights_layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid weights_layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "setWeightsValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else if (weights[weights_layer].size() - 1 < index_neuron || index_neuron < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid index_neuron in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "setWeightsValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else if (weights[weights_layer][index_neuron].size() - 1 < index_weights || index_weights < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid index_neuron in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "setWeightsValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		weights[weights_layer][index_neuron][index_weights] = value;
	}
}
void EdNN::setActFunction(int layer, EdNN::functions act_func)
{
	if (layer > layers_count - 1 || layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "setActFunction";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		act_functions[layer] = act_func;
	}
}

double EdNN::getNeuronValue(int layer, int index_neuron)
{
	if (layer > layers_count - 1 || layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "getNeuronValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else if (neurons[layer].size() - 1 < index_neuron || index_neuron < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid index in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "getNeuronValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		return neurons[layer][index_neuron];
	}

	return -1;
}
double EdNN::getWeightsValue(int weights_layer, int index_neuron, int index_weights)
{
	if (weights_layer > weights_count - 1 || weights_layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid weights_layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "getWeightsValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else if (weights[weights_layer].size() - 1 < index_neuron || index_neuron < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid index_neuron in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "getWeightsValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else if (weights[weights_layer][index_neuron].size() - 1 < index_weights || index_weights < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid index_neuron in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "getWeightsValue";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		return weights[weights_layer][index_neuron][index_weights];
	}

	return -1;
}
EdNN::functions EdNN::getActFunction(int layer)
{
	if (layer > layers_count - 1 || layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "getActFunction";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		return act_functions[layer];
	}

	return EdNN::functions::error;
}

void EdNN::printNeuronsLayer(int layer)
{
	if (layer > layers_count - 1 || layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "printNeuronsLayer";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 3); // blue

		for (int i = 0; i < neurons[layer].size(); ++i)
		{
			std::cout << "neuron[" << i << "] = " << neurons[layer][i] << std::endl;
		}

		std::cout << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
}
void EdNN::printWeightsLayer(int layer)
{
	if (layer > weights_count - 1 || layer < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid layer in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "printWeightsLayer";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white
	}
	else
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 5); // purple
		for (int i = 0; i < weights[layer].size(); ++i)
		{
			for (int j = 0; j < weights[layer][i].size(); ++j)
			{
				std::cout << "weights[" << layer << "][" << i << "][" << j << "] = " << weights[layer][i][j] << std::endl;
			}
			std::cout << std::endl;
		}
		SetConsoleTextAttribute(hwnd, 7); // white
	}
}

void EdNN::backPropagation(int index_valid_neuron)
{
	if (neurons[layers_count - 1].size() - 1 > index_valid_neuron || index_valid_neuron < 0)
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << "Error: invalid index_valid_neuron in { ";

		SetConsoleTextAttribute(hwnd, 6); // orange
		std::cout << "EdNN";

		SetConsoleTextAttribute(hwnd, 7); // white
		std::cout << "::";

		SetConsoleTextAttribute(hwnd, 3); // blue
		std::cout << "backPropagation";

		SetConsoleTextAttribute(hwnd, 4); // red
		std::cout << " }" << std::endl;

		SetConsoleTextAttribute(hwnd, 7); // white

		return;
	}

	if (act_functions[layers_count - 1] == EdNN::functions::SOFTMAX)
	{
		for (int i = 0; i < neurons[layers_count - 1].size(); ++i)
		{
			if (i == index_valid_neuron)
			{
				neurons[layers_count - 1][i] = 1;
			}
			else
			{
				neurons[layers_count - 1][i] = 0;
			}
		}
	}

}