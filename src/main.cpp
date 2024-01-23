/* Copyright (C) 
 * 2024 - Aleksandar Dikov (528052)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

#include "Machine.h"
#include <fstream>
#include <vector>
#include"assembler.h"

int main(int argc, char * argv[]){

    	VM::Machine vm;
	//if you want to use command line arguments 
	if(argc >= 2) vm.loadProg(argc, argv); 

	else{
	VM::assembler assembler(argv[1]); 
	
	auto name = assembler.getFileName(); 

	std::ifstream iss(name, std::ios::binary);

	uint32_t inst; 
	std::vector<uint32_t> prog; 

	while (iss.read((char*)&inst, sizeof(inst))) {
		prog.push_back(inst);

	}
    vm.loadProg(prog);
	}

    vm.run();
    return 0;
}
