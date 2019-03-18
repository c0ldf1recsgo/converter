#include "Thịnh_Deadline2.h"

void reverseStr(string &str) {
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

string convertDecToHex(string Dec)
{
	string Bin;
	string HexDec;
	Bin = convertDecToBin(Dec);
	HexDec = convertBinToHex(Bin);
	return HexDec;
}

string convertBinToDec(string Bin)
{
	string decimal, temp, num;
	decimal = "0";

	int n = Bin.length();
	for (int i = n - 1; i >= 0; i--)
	{
		num = Bin[i];
		temp = Mult(num, Pow("2", n - i - 1));
		decimal = Sum(decimal, temp);
	}
	return decimal;
}

string convertBinToHex(string Bin)
{
	string hexadec, temp, num;
	num = "";
	hexadec = "";

	int n = Bin.length();
	if (n % 4 == 3)
		Bin = "0" + Bin;
	if (n % 4 == 2)
		Bin = "00" + Bin;
	if (n % 4 == 1)
		Bin = "000" + Bin;
	temp = Bin;
	reverseStr(temp);

	for (int i = 0; i < n; i++)
	{
		num = temp[i] + num;
		num = temp[i + 1] + num;
		num = temp[i + 2] + num;
		num = temp[i + 3] + num;
		if (num == "0000")
			hexadec = "0" + hexadec;
		else if (num == "0001")
			hexadec = "1" + hexadec;
		else if (num == "0010")
			hexadec = "2" + hexadec;
		else if (num == "0011")
			hexadec = "3" + hexadec;
		else if (num == "0100")
			hexadec = "4" + hexadec;
		else if (num == "0101")
			hexadec = "5" + hexadec;
		else if (num == "0110")
			hexadec = "6" + hexadec;
		else if (num == "0111")
			hexadec = "7" + hexadec;
		else if (num == "1000")
			hexadec = "8" + hexadec;
		else if (num == "1001")
			hexadec = "9" + hexadec;
		else if (num == "1010")
			hexadec = "A" + hexadec;
		else if (num == "1011")
			hexadec = "B" + hexadec;
		else if (num == "1100")
			hexadec = "C" + hexadec;
		else if (num == "1101")
			hexadec = "D" + hexadec;
		else if (num == "1110")
			hexadec = "E" + hexadec;
		else if (num == "1111")
			hexadec = "F" + hexadec;
		num = "";
		i += 3;
	}
	return hexadec;
}

string convertDecToBin(string Dec)
{
	string div_result, temp, temp_res;
	string Bin = "";

	div_result = Dec;
	if (div_result[0] == '-')
	{
		Bin = "1" + Bin;
		div_result = div_result.erase(0,1);
	}

	while (div_result != "0")
	{
		temp_res = Div(div_result, "2");
		if (temp_res == "0")
			temp = div_result;
		else {
			temp = Diff(div_result, Mult(temp_res, "2"));
			if (temp == "")
				temp = "0";
		}
		if (temp == "1")
			Bin = "1" + Bin;
		else if (temp == "0")
			Bin = "0" + Bin;
		div_result = Div(div_result, "2");
	}
	return Bin;
}

string convertHexToBin(string Hex)
{
	string Bin = "";
	int n = Hex.length();
	for (int i = 0; i < n; i++)
	{
		if (Hex[i] == '0')
			Bin = Bin + "0000";
		else if (Hex[i] == '1')
			Bin = Bin + "0001";
		else if (Hex[i] == '2')
			Bin = Bin + "0010";
		else if (Hex[i] == '3')
			Bin = Bin + "0011";
		else if (Hex[i] == '4')
			Bin = Bin + "0100";
		else if (Hex[i] == '5')
			Bin = Bin + "0101";
		else if (Hex[i] == '6')
			Bin = Bin + "0110";
		else if (Hex[i] == '7')
			Bin = Bin + "0111";
		else if (Hex[i] == '8')
			Bin = Bin + "1000";
		else if (Hex[i] == '9')
			Bin = Bin + "1001";
		else if (Hex[i] == 'A')
			Bin = Bin + "1010";
		else if (Hex[i] == 'B')
			Bin = Bin + "1011";
		else if (Hex[i] == 'C')
			Bin = Bin + "1100";
		else if (Hex[i] == 'D')
			Bin = Bin + "1101";
		else if (Hex[i] == 'E')
			Bin = Bin + "1110";
		else if (Hex[i] == 'F')
			Bin = Bin + "1111";
	}

	return Bin;
}

string convertHexToDec(string Hex)
{
	string Bin, Dec;
	Bin = convertHexToBin(Hex);
	Dec = convertBinToDec(Bin);
	return Dec;
}