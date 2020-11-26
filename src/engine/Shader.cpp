#include "Shader.h"
#include "Core.h"
#include "Exception.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

namespace myengine
{
	void Shader::OnLoad(std::string fileLoc)
	{
		fileLocation = fileLoc;
		shaderContent = "";
		std::string shaderfile= ReadFile(fileLocation.c_str());
		std::cout << "["<<shaderfile<<"]"<<std::endl;
		shaderContent = shaderfile;

	}

	std::string Shader::ReadFile(const char* fileLocation)
	{
		std::string content;
		std::ifstream fileStream(fileLocation, std::ios::in);

		if (!fileStream.is_open()) {
			std::string error="Failed to read %s! File doesn't exist.", fileLocation;
			throw Exception(error);

			return "";
		}

		std::string line = "";
		content = "\n";
		while (!fileStream.eof())
		{
			std::getline(fileStream, line);
			content+=line + "\n";
		}

		fileStream.close();
		return content;
	}

	Shader::~Shader()
	{

	}
}