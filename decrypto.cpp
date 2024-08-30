#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

void Encode(const std::string& inFileName,
			const std::string& outFileName,
			const std::string& header)
{
	std::ifstream infile(inFileName, std::ios::binary);
	std::ofstream outfile(outFileName, std::ios::binary);
	if (!infile || !outfile)
	{
		std::cerr << "Error occur on Read/Write targe file!\n";
		return;
	}
	outfile.write(header.c_str(), header.size());
	char byte;
	while (infile.get(byte))
	{
		byte = (byte == 0xFF) ? 0x00 : byte + 1;
		outfile.put(byte);
	}
	infile.close();
	outfile.close();
}

void Decode(const std::string& inFileName,
			const std::string& outFileName,
			const std::string& header)
{
	std::ifstream infile(inFileName, std::ios::binary);
	std::ofstream outfile(outFileName, std::ios::binary);
	if (!infile)
	{
		std::cerr << "Error occur input file!\n";
		return;
	}
	if (!outfile)
	{
		std::cerr << "Error occur on output file!\n";
		return;
	}
	std::string fileHeader(header.size(), '\0');
	infile.read(&fileHeader[0], header.size());
	if (fileHeader != header) {
		std::cerr << "Header mismatch.\n";
		return;
	}
	// Decrypt file data
	char byte;
	while (infile.get(byte)) {
		byte = (byte == 0x00) ? 0xFF : byte - 1; // mod 16 operation for each byte
		outfile.put(byte);
	}
	infile.close();
	outfile.close();
}

int main(int count , char** cmdArgs)
{
	//Decode("aaaa.mp4", "bbbbc.mp4", "JJJJ");
	if (count < 4) 
	{
		std::cerr << "No argument provided." << std::endl;
		return -1;
	}
	if (count > 4)
	{
		std::cerr << "Too many parameters provided." << std::endl;
		return -1;
	}
	// count = 4
	std::string opt = cmdArgs[1];
	std::string inFileName = cmdArgs[2];
	std::string outFileName = cmdArgs[3];
	std::string header = "JJJJ";
	if ( opt == "-e" || opt == "-E")
	{
		std::cout << "Encode task." << std::endl;
		Encode(inFileName, outFileName, header);
		system("pause");
		return 0;
	}
	if ( opt == "-d" || opt == "-D")
	{
		std::cout << "Decode task." << std::endl;
		Decode(inFileName, outFileName, header);
		system("pause");
		return 0;
	}
	std::cerr << "Invaild option. Use -e or -E for encode, -d or -D for decode\n" << std::endl;
	system("pause");
	return -1;
}