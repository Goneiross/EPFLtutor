/*!
  \file   main.cc
  \brief  Commandline based interface. Coordinate the different modules.
*/

#include <iostream>
#include <string>

#include "configuration.h"

#define TYPE_SPECIFIC_HELP 0
#define TYPE_SUBJECT 1
#define TYPE_SERIE 2
#define TYPE_EXERCISE 3

using namespace std;

typedef struct dataAdress {
  string subject;
  string serie;
  string exercise;
} dataAdress;

void create(int argc, char *argv[], int &argNb);
void list(int argc, char *argv[], int &argNb);
void show(int argc, char *argv[], int &argNb);
void stats(int argc, char *argv[], int &argNb);
int edit(int argc, char *argv[], int &argNb);
void help();

void parseTypeArg(int argc, char *argv[], int &argNb, int &type, dataAdress &adress);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "Type '--help' for a list of commands" << endl;
    } else {
        for (int argNb = 1; argNb < argc; argNb++) {
          if (string(argv[argNb]) == "-h" or string(argv[argNb]) == "--help") {
            help();
          } else if (string(argv[argNb]) == "-c" or string(argv[argNb]) == "--create") {
            create(argc, argv, argNb);
          } else if (string(argv[argNb]) == "-l" or string(argv[argNb]) == "--list") {
            list(argc, argv, argNb);
          } else if (string(argv[argNb]) == "-sh" or string(argv[argNb]) == "--show") {
            show(argc, argv, argNb);
          } else if (string(argv[argNb]) == "-s" or string(argv[argNb]) == "--stats") {
            stats(argc, argv, argNb);
          } else if (string(argv[argNb]) == "-e" or string(argv[argNb]) == "--edit") {
            // Call list functions
          } else if (string(argv[argNb]) == "--config") {
            config(argc, argv, argNb);
          } else {
            cout << string(argv[argNb]) << " is not recognized" << endl;
            exit(0);
          }
        }
    }
    return 0;
}

void create(int argc, char *argv[], int &argNb) {
  argNb++;
  if (argNb >= argc) {
    cout << "Please, provide an argument to tell what you want to create." << endl
         << "For example, -subject to create a new subject." << endl
         << "For more informations, type --help" << endl;
    exit(0);
  }
  bool realTime = false;
  int type;
  dataAdress adress;
  if (string(argv[argNb]) == "-realTime") { realTime = true; }
  cout << "Creating:";
  parseTypeArg(argc, argv, argNb, type, adress);
  cout << endl;
  if (type == TYPE_SPECIFIC_HELP) {
    cout << "This is specific help" << endl;
    exit(0);
  }
  exit(0);
}

void list(int argc, char *argv[], int &argNb) {
  argNb++;
  if (argNb >= argc) {
    cout << "Please, provide an argument to tell which list you want." << endl
         << "For example, -subject to list all the subjects." << endl
         << "For more informations, type --help" << endl;
    exit(0);
  }
  if (string(argv[argNb]) == "--help") {
    cout << "This is specific help" << endl;
    exit(0);
  } if (string(argv[argNb]) == "-subject") {
    // Call read function to parse subject names
    // Cout list
    exit(0);
  } else if (string(argv[argNb]) == "-serie") {
    // Call read function to parse data
    // Cout list
    exit(0);
  } else if (string(argv[argNb]) == "-exercise") {
    // Call read function to parse data
    // Cout list
    exit(0);
  }
}

void show(int argc, char *argv[], int &argNb) {
    argNb++;
  if ( argNb >= argc){
    cout << "Please, provide an argument to tell which information you want." << endl
         << "For more informations, type --help" << endl;
    exit(0);
  }
  int type;
  dataAdress adress;
  cout << "Showing:";
  parseTypeArg(argc, argv, argNb, type, adress);
  cout << endl;
  if (type == TYPE_SPECIFIC_HELP) {
    cout << "This is specific help" << endl;
    exit(0);
  }
  // Get other arguments, for example which info : -all, -marks, -tags, ...
  exit(0);
}

void stats(int argc, char *argv[], int &argNb){
  argNb++;
  if (argNb < argc) {
    if (string(argv[argNb]) == "--help") {
      cout << "This is specific help" << endl;
      exit(0);
    }
  }
  // To do later
  exit(0);
}

void help() {
  cout << "EPFLtutor 0.0.1" << endl
       << "This is free software: you are free to change and redistribute it, just name the main authors." << endl
       << "See: https://github.com/Goneiross/EPFLtutor for more informations and tutorials." << endl << endl;
  cout << "Commands:" << endl
       << "-h,  --help                show the help" << endl
       << "-l,  --list                " << endl
       << "-c,  --create              " << endl
       << "     --create -realTime    do an exercise or a serie in real time (needs a parameters)"
       << "-s,  --stats               " << endl
       << "-e,  --edit                " << endl
       << "-sh, --show                " << endl << endl;
  cout << "Parameters:" << endl
       << "-subject                   " << endl
       << "-serie                     " << endl
       << "-exercise                  " << endl << endl;
  cout << "Examples of use:" << endl
       << "EPFLtutor --create -subject Analysis -serie               Create a new serie in Analyse" << endl
       << "EPFLtutor --show -subject Algebra -serie 4 -exercise 1    Show the first exercise of the 4h serie in Algebra" << endl
       << "EPFLtutor --list -subject Physics -serie                  List all Physics series" << endl << endl;
  exit(0);
}

void parseTypeArg(int argc, char *argv[], int &argNb, int &type, dataAdress &adress) {
  while (argNb < argc ) {
    if (string(argv[argNb]) == "--help") {
      argNb++;
      type = TYPE_SPECIFIC_HELP;
      return;
    } else if (string(argv[argNb]) == "-subject") {
      argNb++;
      type = TYPE_SUBJECT;
      cout << " subject ";
      if (argNb < argc) { adress.subject = string(argv[argNb]); cout << adress.subject; argNb++; type = TYPE_SERIE; }
    } else if (string(argv[argNb]) == "-serie") {
      argNb++;
      type = TYPE_SERIE;
      cout << ", serie ";
      if (argNb < argc) { adress.serie = string(argv[argNb]); cout << adress.serie ; argNb++; type = TYPE_EXERCISE; }
    } else if (string(argv[argNb]) == "-exercise") {
      argNb++;
      type = TYPE_EXERCISE;
      cout << ", exercise ";
      if (argNb < argc) { adress.exercise = string(argv[argNb]); cout << adress.exercise; argNb++; }
    }
  }
}