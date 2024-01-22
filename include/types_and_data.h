#pragma once
/**
 * @file types_and_data.h 
 */

/**
 * @file types_and_data.h
 * @brief Types and Data
 * @author Stiliyan Batinkov (530007)
 * @version 1.2
 * @date 2024-01-18
 *
 * This class holds the values for the different data types, instructions and states. This file is used by all other header files (Machine.h, assembler.h, lexer.h)
 */

/**
 * @brief 
 */
enum {
    POS_INT = 0, /**< Positive integer. */
    INSTRUCTION, /**< Instruction. */
    NEG_INT      /**< Negative integer. */
};

/**
 * @brief Enumeration representing arithmetic operations.
 * This is Used by assembler.h to parse the syntax of the input file into instructions for the machine. 
 */
enum {
    PLUS = '+',    /**< Addition operation. */
    MINUS = '-',   /**< Subtraction operation. */
    MULTI = '*',   /**< Multiplication operation. */
    DIVIDE = '/'    /**< Division operation. */
};

/**
 * @brief Enumeration for  virtual machine instructions.
 * This is used by machine.h to preform logical operations for the calculator. 
 *
 */
enum {
    HALT = 0,  /**< Halt  */
    ADD,       /**< Addition   */
    SUB,       /**< Subtraction   */
    MUL,       /**< Multiplication   */
    DIV,       /**< Division   */
    OP_AND,    /**< Logical AND   */
    OP_OR,     /**< Logical OR   */
    LOD        /**< Load   */
};

/**
 * @brief Enumeration representing states in the state machine.
 * This is used by lexer.h for converting the bytes from the input file into  a binary format for the virtual machine. 
 */
enum State : char {
    START,      /**< Initial state. */
    READCHAR,   /**< Reading characters. */
    READBLOCK,  /**< Reading blocks of characters. */
    SKIP,       /**< Skipping characters. */
    DUMP,       /**<  Dumping information. */
    END         /**< End state. */
};

