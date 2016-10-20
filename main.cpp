/*
 * main.cpp
 *
 *  Created on: 23/ago/2016
 *      Author: MUNARID
 */

#include <cstdio>
#include <vector>
/*
 * Aggiungere sempre qualche commento
 *
 */
int parse_tags(char *inp_str, char** tag, std::vector<char *> &fields, std::vector<char *> &values){

	char *cur = 0;
	char *field_name = 0;
	char *field_value = 0;

	cur = inp_str;
	if (cur[0] != '<')
		return -1;
	cur++;
	if (cur[0] == ' ')
		while (cur[0] == ' ')
			cur++; // stops on first char (tag)
	*tag = cur;
	while (cur[0] != ' ')
		cur++; // stops on first blank
	cur[0] = 0; // end of string tag name
	cur++;
	if (cur[0] == ' ')
		while (cur[0] == ' ')
			cur++; // stops on first char (field name)

	while (cur[0] != '>') {
		field_name = cur;
		while (cur[0] != ' ')
			cur++; // stops on first blank
		cur[0] = 0; // end of string field_name
		cur++;
		if (cur[0] != '=')
			return -1;
		cur++;
		if (cur[0] != ' ')
			while (cur[0] == ' ')
				cur++; // stops on first char
		cur++;
		if (cur[0] != '\"')
			return -1;
		cur++;
		field_value = cur;
		while (cur[0] != '\"')
			cur++; // stops on first char
		cur[0] = 0; // end of string field_value
		cur++;
		if (cur[0] == ' ')
			while (cur[0] == ' ')
				cur++; // stops on first char (field name)
		fields.push_back(field_name);
		values.push_back(field_value);
	}

	return 0;
}

int main(int argc, char * argv[]) {
	char inp[] = "<tag1 value = \"Hello World\" field1 = \"Goodbye World\">";
	char* tag;
	std::vector<char *>  fields_names;
	std::vector<char *>  fields_values;

	parse_tags(inp, &tag, fields_names, fields_values);

	printf("%s\n", tag);
	printf("%s\n", fields_names[1]);
	printf("%s\n", fields_values[1]);

	return 0;
}

