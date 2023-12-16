#pragma once
#include <vector>;

class EdNN
{
public: //enums
	enum class functions
	{
		NOTHING,
		RELU,
		SOFTMAX,
		error
	};

private: //varibles
	std::vector<std::vector<double>> neurons;
	std::vector<std::vector<std::vector<double>>> weights;
	std::vector<functions> act_functions;

	int layers_count = 0;
	int weights_count = 0;

public:
	EdNN() = delete;
	EdNN(int count_neurons);

	~EdNN();

	void addLayer(int count_neurons, EdNN::functions act_func);

	void setNeuronValue(int layer, int index_neuron, double value);
	void setWeightsValue(int weights_layer, int index_neuron, int index_weights, double value);
	void setActFunction(int layer, EdNN::functions act_func);

	double getNeuronValue(int layer, int index_neuron);
	double getWeightsValue(int weights_layer, int index_neuron, int index_weights);
	EdNN::functions getActFunction(int layer);

	void printNeuronsLayer(int layer);
	void printWeightsLayer(int layer);

	void backPropagation(int index_valid_neuron);

private: //act_funcs
	double act_func_relu(double x);
	double act_func_relu_differential(double x);

};