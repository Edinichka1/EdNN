#include <iostream>
#include <Windows.h>
#include "EdNN.h"

int main()
{
	EdNN myNetwork(28*28);

	myNetwork.addLayer(128, EdNN::functions::RELU);

	myNetwork.addLayer(10, EdNN::functions::SOFTMAX);

	//back propagation не дописана

	return 0;
}