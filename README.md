# 🧠 Lexical Analyzer in C

This project implements a **lexical analyzer (lexer)** for the C programming language. The lexer parses a given `.c` source file and converts it into a sequence of **tokens**, such as keywords, operators, identifiers, literals, and punctuation. It simulates the first phase of a compiler.

---

## 🎯 Project Goal

To tokenize a valid C source file into lexical units (tokens) based on grammar rules. This lays the foundation for compiler design and parsing.

---

## 🧾 Key Features

- Identifies common token types:
  - **Identifiers**
  - **Keywords**
  - **Operators**
  - **Literals** (integers, floats)
  - **Delimiters** (commas, semicolons, braces)
- Handles whitespaces and ignores comments
- Displays tokens in a readable tabular format
- Detects invalid/unrecognized tokens
- Command-line interface for tokenizing any `.c` file

---

## 🧰 Technologies

- **Language:** C
- **Concepts:** File I/O, String parsing, FSM, Regex-like logic
- **Inspiration:** Lex and Yacc

---


