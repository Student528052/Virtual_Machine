#include <vector>
#include <string>

/**
 * @file assembler.h
 * @brief Assembler file for transforming the input file into instructions
 * @author Aleksandar Dikov (528052)
 * @version 
 * @date 2024-01-20
 */

namespace VM {

    /**
     * @brief The assembler class for Virtual Machine.
     * This class provides functionality to assemble instructions and write them to a binary file.
     */
    class assembler {
    public:
        /**
         * @brief Default constructor for the assembler class.
         */
        assembler() = default;

        /**
         * @brief Parameterized constructor for the assembler class.
         * @param fname Input file.
         */
        assembler(std::string& fname);

        /**
         * @brief Parameterized constructor for the assembler class.
         * @param fname Input file .
         */
        assembler(const char* fname);

        /**
         * @brief Compiles a vector of assembly instructions into machine code.
         * @param str Vector of strings containing assembly instructions.
         * @return Vector of 32-bit unsigned integers representing compiled instructions.
         */
        std::vector<uint32_t> compile_instructions(std::vector<std::string>& str);

        /**
         * @brief Gets the file pointer of the assembled binary file.
         * @return File pointer to the assembled binary file.
         */
        std::FILE* getFile();

        /**
         * @brief Gets the name of the file being assembled.
         * @return The name of the file being assembled.
         */
        std::string getFileName();

        /**
         * @brief Maps a character to its corresponding instruction in machine code.
         * @param c The character to be mapped.
         * @return The machine code instruction corresponding to the input character.
         */
        uint32_t map_to_intstuction(char& c);

        /**
         * @brief Writes the assembled instructions to a specified file.
         * @param fname The name of the file to write the assembled instructions to.
         */
        void assemble_to(const char* fname);

    private:
        /**
         * @brief Checks if a string represents an integer.
         * @param str The string to be checked.
         * @return True if the string represents an integer, false otherwise.
         */
        bool isInt(std::string str);

        /**
         * @brief File pointer to the binary file containing assembled instructions.
         */
        std::FILE* m_file;

        /**
         * @brief File destination
         */
        std::string m_fname;
    };

}; //namespace VM
