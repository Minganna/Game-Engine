#include "Model.h"
#include "Core.h"
#include "Exception.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

namespace myengine
{
	void Model::OnLoad(std::string fileLoc)
	{
		fileLocation = fileLoc;
		ReadFile(fileLocation);
	}

	void Model::ReadFile(std::string fileLocation)
	{
		shape = GetCore()->context->createMesh();
		std::ifstream file(fileLocation);

		if (!file.is_open())
		{
			std::string error = ("Failed to find: %s\n", fileLocation.c_str());
			throw Exception(error);
		}

		std::string content;
		std::string line;

		while (!file.eof())
		{
			std::getline(file, line);
			content += line + "\n";
		}
		shape->parse(content);
	}

	Model::~Model()
	{

	}
}