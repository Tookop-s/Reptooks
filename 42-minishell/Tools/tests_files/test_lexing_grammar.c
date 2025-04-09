#include <assert.h>
#include "minishell.h"

typedef struct {
    char *expected_input;
    t_token_type expected_type;
} ExpectedToken;

typedef struct {
    char *input;
    ExpectedToken *expected_tokens;
    int num_expected_tokens;
	int num_expected_cmds;
} Test;

void test_lexing(){
    ExpectedToken test1_tokens[] = {{"command1", token_word}, {"|", token_pipe}, {"command2", token_word}};
	ExpectedToken test2_tokens[] = {{"command1", token_word}, {"&&", token_and_and}, {"command2", token_word}};
	ExpectedToken test3_tokens[] = {{"command1", token_word}, {"||", token_or}, {"command2", token_word}};
	ExpectedToken test4_tokens[] = {{"command1", token_word}, {"<", token_left_dir}, {"file1", token_word}, {">", token_right_dir}, {"file2", token_word}};
	ExpectedToken test5_tokens[] = {{"command1", token_word}, {"'argument with spaces'", token_word}};
	ExpectedToken test6_tokens[] = {{"(null)", token_word}};
	ExpectedToken test7_tokens[] = {{"", token_word}};
	ExpectedToken test8_tokens[] = {{"command1", token_word}, {"|", token_pipe}, {"command2", token_word}};
	ExpectedToken test9_tokens[] = {{"command1", token_word}, {"|", token_pipe}, {"command2", token_word}};
	ExpectedToken test10_tokens[] = {{"command1", token_word}, {"|", token_pipe}, {"command2", token_word}};
	ExpectedToken test11_tokens[] = {{"command1", token_word}, {"'argument with spaces'", token_word}};
	ExpectedToken test12_tokens[] = {{"command1", token_word}, {"\"argument with spaces\"", token_word}};
	ExpectedToken test13_tokens[] = {{"command1", token_word}, {"'argument with spaces'", token_word}, {"\"another argument with spaces\"", token_word}};
	ExpectedToken test14_tokens[] = {{"command1", token_word}, {"\"argument\nwith\nnewlines\"", token_word}};
	ExpectedToken test15_tokens[] = {{"command1", token_word}, {"\"argument with 'nested' quotes\"", token_word}};
	ExpectedToken test16_tokens[] = {{"command1", token_word}, {"\"Hello, $USER!\"", token_word}};
	ExpectedToken test17_tokens[] = {{"command1", token_word}, {"\"Hello, $(whoami)!\"", token_word}};
	ExpectedToken test18_tokens[] = {{"command1", token_word}, {"<<", token_here_doc}, {"EOF", token_word}, {"command2", token_word}};
	ExpectedToken test19_tokens[] = {{"command1", token_word}, {">>", token_dright_dir}, {"file1", token_word}};
	ExpectedToken test20_tokens[] = {{"command1", token_word}, {"<<", token_here_doc}, {"EOF", token_word}, {">>", token_dright_dir}, {"file1", token_word}};
	ExpectedToken test21_tokens[] = {};
	ExpectedToken test22_tokens[] = {};
	ExpectedToken test23_tokens[] = {};
	ExpectedToken test24_tokens[] = {};
	ExpectedToken test25_tokens[] = {};
	ExpectedToken test26_tokens[] = {};
	ExpectedToken test27_tokens[] = {};
	ExpectedToken test28_tokens[] = {};
	ExpectedToken test29_tokens[] = {};
	ExpectedToken test30_tokens[] = {};
	ExpectedToken test31_tokens[] = {};
	ExpectedToken test32_tokens[] = {};
	ExpectedToken test33_tokens[] = {};
	ExpectedToken test34_tokens[] = {};
	ExpectedToken test35_tokens[] = {};
	ExpectedToken test36_tokens[] = {};
	ExpectedToken test37_tokens[] = {{"command1", token_word}};
	ExpectedToken test38_tokens[] = {{"command1", token_word}};
	ExpectedToken test39_tokens[] = {{"command1", token_word}};
	ExpectedToken test40_tokens[] = {{" ", token_word}};
	ExpectedToken test41_tokens[] = {{"command1", token_word}, {"command2", token_word}};
	ExpectedToken test42_tokens[] = {{"command1", token_word}, {"command2", token_word}, {"command3", token_word}};
	ExpectedToken test43_tokens[] = {{"command1", token_word}, {"command2", token_word}, {"command3", token_word}, {"command4", token_word}};

	Test tests[] = {
		{"command1|command2", test1_tokens, 3, 1},
		{"command1 && command2", test2_tokens, 3, 1},
		{"command1 || command2", test3_tokens, 3, 1},
		{"command1 <file1>file2", test4_tokens, 5, 1},
		{"command1 'argument with spaces'", test5_tokens, 2, 1},
		{"", test6_tokens, 1, 0},
		{"     ", test7_tokens, 1, 1},
		{"   command1 | command2   ", test8_tokens, 3, 1},
		{"command1   |   command2", test9_tokens, 3, 1},
		{"command1|command2", test10_tokens, 3, 1},
		{"command1 'argument with spaces'", test11_tokens, 2, 1},
		{"command1 \"argument with spaces\"", test12_tokens, 2, 1},
		{"command1 'argument with spaces' \"another argument with spaces\"", test13_tokens, 3, 1},
		{"command1 \"argument\nwith\nnewlines\"", test14_tokens, 2, 1},
		{"command1 \"argument with 'nested' quotes\"", test15_tokens, 2, 1},
		{"command1 \"Hello, $USER!\"", test16_tokens, 2, 1},
		{"command1 \"Hello, $(whoami)!\"", test17_tokens, 2, 1},
		{"command1 << EOF command2", test18_tokens, 4, 1},
		{"command1 >> file1", test19_tokens, 3, 1},
		{"command1 << EOF >> file1", test20_tokens, 5, 1},
		{"command1 && || command2", test21_tokens, 0, 0},
		{"command1 (command2 && command3", test22_tokens, 0, 0},
		{"command1 && || command2", test23_tokens, 0, 0},
		{"command1 |", test24_tokens, 0, 0},
		{"command1 >>", test25_tokens, 0, 0},
		{"command1 && && command2", test26_tokens, 0, 0},
		{"command1 || || command2", test27_tokens, 0, 0},
		{"command1 | | command2", test28_tokens, 0, 0},
		{"command1 < < file1", test29_tokens, 0, 0},
		{"command1 > > file1", test30_tokens, 0, 0},
		{"command1 && | command2", test31_tokens, 0, 0},
		{"command1 || && command2", test32_tokens, 0, 0},
		{"command1 (command2 && command3", test33_tokens, 0, 0},
		{"command1 command2) && command3", test34_tokens, 0, 0},
		{"command1 (command2 && command3))", test35_tokens, 0, 0},
		{"((command1 command2) && command3", test36_tokens, 0, 0},
		{"\ncommand1", test37_tokens, 1, 1},
		{"command1\n", test38_tokens, 1, 1},
		{"\ncommand1\n", test39_tokens, 1, 1},
		{"\n \n", test40_tokens, 1, 0},
		{"command1\n \ncommand2", test41_tokens, 1, 2},
		{"command1\ncommand2\ncommand3", test42_tokens, 1, 3},
		{"command1\ncommand2\ncommand3\ncommand4", test43_tokens, 1, 4},
	};

	
	for (size_t i = 0; i < sizeof(tests) / sizeof(Test); i++)
	{
		int p = 0;
		int a = 0;
		printf("\033[0;34mTest %lu \033[0m\n", i + 1);
		t_command *command = ft_lexing(tests[i].input);
		while (command)
		{
			p++;
			if (tests[i].num_expected_tokens == 0)
			{
				assert(command->token== NULL);
				printf("Original bash output:\n");
				char command[256];
				snprintf(command, sizeof(command), "%s 2>&1", tests[i].input);
				system(command);
				printf("\n");
				printf("\033[0;32mTest %lu passed \033[0m\n\n", i + 1);
				continue;
			}
			assert(command->token != NULL);
			for (int j = 0; j < tests[i].num_expected_tokens; j++)
			{
				// if (i == 5)
				// 	printf("token->input: $%s$ expected input $%s$\n", command->token->input, tests[i].expected_tokens[j].expected_input);
				if (a == 1)
					j += p - 1;
				if (command->token->input != NULL)
				{
					assert(strcmp(command->token->input, tests[i].expected_tokens[j].expected_input) == 0);
					assert(command->token->type == tests[i].expected_tokens[j].expected_type);
				}
				else
				{
					assert(command->token->input == NULL);
				}
				command->token = command->token->next;
			}
			command = command->next;
			a = 1;		
		}
		assert(p == tests[i].num_expected_cmds);
		printf("\033[0;32mTest %lu passed \033[0m\n\n", i + 1);
	}
}

int main() {
    test_lexing();
    printf("All tests passed!\n");
    return 0;
}

//returns the string name of the token type
// char	*ft_get_enum(int token)
// {
// 	if (token == token_pipe)
// 		return ("token_pipe");
// 	if (token == token_or)
// 		return ("token_or");
// 	if (token == token_left_par)
// 		return ("token_left_par");
// 	if (token == token_right_par)
// 		return ("token_right_par");
// 	if (token == token_word)
// 		return ("token_word");
// 	if (token == token_and_and)
// 		return ("token_and_and");
// 	if (token == token_left_dir)
// 		return ("token_left_dir");
// 	if (token == token_right_dir)
// 		return ("token_right_dir");
// 	if (token == token_here_doc)
// 		return ("token_here_doc");
// 	if (token == token_dright_dir)
// 		return ("token_dright_dir");
// 	if (token == token_newline)
// 		return ("token_newline");
// 	return ("none");
// }