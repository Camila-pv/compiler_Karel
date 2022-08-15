#include<iostream>
#include<regex>
#include<string>
#include<fstream>
#include<vector>

bool gramatica(std::vector<std::string> &myvec);
bool gram_start(std::vector<std::string> &myvec);
bool gram_program(std::vector<std::string> &myvec);
bool gram_definition(std::vector<std::string> &myvec);

/**
bool gram_statement(std::vector<std::string> myvec);
bool gram_block(std::vector<std::string> myvec);
bool gram_iteration(std::vector<std::string> myvec);
bool gram_loop(std::vector<std::string> myvec);
bool gram_conditional(std::vector<std::string> myvec);
bool instruction(std::vector<std::string> myvec);

**/
/**
 GRAMATICA KAREL
 
 start → BEGINNING−OF−PROGRAM program END−OF−PROGRAM
 program → definition∗ BEGINNING−OF−EXECUTION statement∗ END−OF−EXECUTION
 definition → DEFINE−NEW−INSTRUCTION identifier AS statement 
 statement → block | iteration | loop | conditional | instruction
 block → BEGIN statement∗ END 
 iteration → ITERATE number TIMES statement
 loop → WHILE condition DO statement
 conditional → IF condition THEN statement (ELSE statement)?
 instruction → TURNON | MOVE | TURNLEFT | PICKBEEPER | PUTBEEPER | TURNOFF | identifier 
 condition → FRONT−IS−CLEAR | FRONT−IS−BLOCKED | LEFT−IS−CLEAR | LEFT−IS−BLOCKED
            | RIGHT−IS−CLEAR | RIGHT−IS−BLOCKED | BACK−IS−CLEAR | BACK−IS−BLOCKED
            | NEXT−TO−A−BEEPER | NOT−NEXT−TO−A−BEEPER | ANY−BEEPERS−IN−BEEPER−BAG
            | NO−BEEPERS−IN−BEEPER−BAG | FACING−NORTH | NOT−FACING−NORTH
            | FACING−SOUTH | NOT−FACING−SOUTH | FACING−EAST | NOT−FACING−EAST
            | FACING−WEST | NOT−FACING−WEST
 identifier → [ a−z ] ( [ a−z ] | [0−9]+ )∗
 number → [0−9]+
**/

int main(){
    std::vector<std::string> myvec;
    int count = 0;
    std::fstream newfile;
  //Leer el programa fuente
  newfile.open("prueba.txt",std::ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
     std::string tp;
      while(getline(newfile, tp)){  //read data from file object and put it into string.
	//Llamar la funció
	myvec.push_back(tp);
      }
      newfile.close();   //close the file object.
   }


   if(gramatica(myvec))
    std::cout << "Verdadero " << std::endl;
  else
    std::cout << "Falso " << std::endl;
   for(int i = 0; i < myvec.size() ; i++)
     std::cout << myvec[i]<<" \n";
    return 0;
}

// LLama a la función gram_start y le pasa el vector
bool gramatica(std::vector<std::string> &myvec){
  return gram_start(myvec);
}


// POR HACER : ESPACION AL INICIO, AL FINAL Y EN EL MEDIO DE TODO EL CODIGO
// Identifica BEGINNING-OF-PROGRAM y END-OF-PROGRAM
// Luego llama a la función gram_program si sigue la ejecucion del programa
// si empieza la creación de una instrucción llama a gram_definition
bool gram_start(std::vector<std::string> &myvec){
  std::vector<std::string> myvec2;
  if(std::regex_match(myvec[0], std::regex("(BEGINNING-OF-PROGRAM)([\\s]*)")) && std::regex_match(myvec[myvec.size()-1],std::regex("(END-OF-PROGRAM)([\\s]*)"))){
    for(int i = 1; i < myvec.size()-1; i++)
      myvec2.push_back(myvec[i]);
    myvec = myvec2;
    if(std::regex_match(myvec[0], std::regex("([\\s]*)(BEGINNING−OF−EXECUTION)([\\s]*)")))
      return gram_program(myvec);
    else
      return gram_definition(myvec);
  }else{
    return false;
  }
}



// POR HACER : TABULACION
// Identifica BEGINNING-OF-EXECUTION y END-OF-EXECUTION
bool gram_program(std::vector<std::string> &myvec){
  std::vector<std::string> myvec2;
  if(std::regex_match(myvec[0], std::regex("([\\s]*)(BEGINNING−OF−EXECUTION)([\\s]*)")) && std::regex_match(myvec[myvec.size()-1],std::regex("([\\s]*)(END-OF-EXECUTION)([\\s]*)"))){
    for(int i = 1; i < myvec.size()-1; i++)
      myvec2.push_back(myvec[i]);
    myvec = myvec2;
    return true;
  }else{
    return false;
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// Identifica la creación de una instrucción
bool gram_definition(std::vector<std::string> &myvec){
  std::vector<std::string> myvec2;
  if(std:: regex_match(myvec[0], std::regex("([\\s]*)(DEFINE-NEW-INSTRUCTION)([\\s]*)([A-Za-z])*([\\s]*)(AS)([\\s]*)"))){
    for(int i = 1;i < myvec.size(); i++)
      myvec2.push_back(myvec[i]);
    myvec= myvec2;   
    std::cout<<"Nueva funcioon\n";
  return true;
   
  }
  return false;
}
///////////////////////////////////////////////////////////////////////////////////////
