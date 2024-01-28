
```markdown
# Tokenizer Program

This program reads a file (`program.txt`) and tokenizes the input into keywords, operators, numbers, and identifiers.

## Usage

1. Make sure you have a file named `program.txt` with the code you want to tokenize.
2. Compile and run the program.
3. The program will output the detected tokens with their types.

## Token Types

- Keyword: Identified programming language keywords.
- Operator: Recognized operators in the code.
- Number: Numeric values found in the code.
- Identifier: Variables or function names.

## How it Works

The program reads each line from the `program.txt` file, separates tokens, and identifies their types based on predefined keywords, operators, and rules for numbers and identifiers.

## Sample input

This program reads a file (`program.txt`) which contain like this code:
int main(){
    int a,bd,8c,_9c,he$fds;	
    int i= 10 + 3;
    i++;
};


## Sample output

int is a keyworkd
main is an Identifier
int is a keyworkd
a is an Identifier
bd is an Identifier
8c is not valid Identifier
_9c is an Identifier
he$fds is not valid Identifier
int is a keyworkd
i is an Identifier
= is a Operator
10 is a Number
+ is a Operator
3 is a Number
i is an Identifier
+ is a Operator
+ is a Operator

  
```

## Contribution

Contributions to this project are welcome. If you find issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

---

**Author:** Aktaruzzaman

**Contact:** Message me on github.
```
