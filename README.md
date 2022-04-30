# Welcome to Paint++-JALLAC

Paint++-JALLAC means Paint++ version Joan, Allan, Carlos.

# Dependencies

Update packages.

```
sudo apt-get -y update
```

Install dependencies

```
sudo apt install -y gcc cmake 
```

```
sudo apt install -y qt5-base
```

```
sudo apt install -y plantuml doxygen
```

```
sudo apt-get install -y cowsay
```
# Rules to code

- Always to programing in poo.
- Use headers files.
- Follow name recommendations

# Names

## Var names

- Inits in lowerCase and do capitalize if you need more information.
- Try to be clear what it is the var.

```c++
    int main(){
        int numberSize;
        return 0;
    }
```

## Function and Methods names

- Inits in lowerCase and do capitalize if you need more information.
- Try to be clear what to the function or methods.

```c++
    #include "iostream"
    using namespace std;
    class Printer{
        public:
            static void myFunctionPrint(){
                cout << "I'm the printer." << endl;
            }
    };

    int main(){
        Printer::myFuctionPrint();
    }
```

## Class name

- Inits in capitalize and do capitalize if you need more information.
- Try to be clear what to the function or methods.

```c++
    #include "iostream"
    using namespace std;
    class MyHelloWord{
        public:
            static void doIt(){
                cout << "Hello Word" << endl;
            }
    };

    int main(){
        MyHelloWord::doIt();
    }
```

# Rules of git
- NEVER programing in master.
- Create a new branch when you finish a feature.
- Create branch name in English without space (you can use - to represent the space).
- Commit message as you can in english.
- Try to be clear in the commit message.
- Try to commit when you finished a function.
- Don't merge into a pattern branch, ask always first.
- When you are going to merge a branch create a new branch for do the merge.

# External Documention
[ [Google Docs File] ](https://docs.google.com/document/d/1W5c8nUWtCWFqbaTTsP8gLxst3JtPFzRZlmOLFBUMxQU/edit?usp=sharing)

# Jira
[[Repository in Jira]](https://achen031199.atlassian.net/jira/projects)


# References

## Project 2 - Paint++-JALLAC

- [[QGridLayout]](https://chowdera.com/2021/04/20210403063919149m.html)
- [[README.md Links]](https://www.codegrepper.com/code-examples/whatever/how+to+create+link+in+readme.md)