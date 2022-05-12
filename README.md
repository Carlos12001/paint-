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


```
sudo apt-get install -y google-glog
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


# Importan Information

## unsigned char with RGB

As for example usages of unsigned char:

unsigned char is often used in computer graphics, which very often (though not always) assigns a single byte to each colour component. It is common to see an RGB (or RGBA) colour represented as 24 (or 32) bits, each an unsigned char. Since unsigned char values fall in the range [0,255], the values are typically interpreted as:

* 0 meaning a total lack of a given colour component.
* 255 meaning 100% of a given colour pigment.
So you would end up with RGB red as (255,0,0) -> (100% red, 0% green, 0% blue).

Why not use a signed char? Arithmetic and bit shifting becomes problematic. As explained already, a signed char's range is essentially shifted by -128. A very simple and naive (mostly unused) method for converting RGB to grayscale is to average all three colour components, but this runs into problems when the values of the colour components are negative. Red (255, 0, 0) averages to (85, 85, 85) when using unsigned char arithmetic. However, if the values were signed chars (127,-128,-128), we would end up with (-99, -99, -99), which would be (29, 29, 29) in our unsigned char space, which is incorrect.

# References

## Project 2 - Paint++-JALLAC

- [ [QGridLayout] ](https://chowdera.com/2021/04/20210403063919149m.html)
- [ [README.md Links] ](https://www.codegrepper.com/code-examples/whatever/how+to+create+link+in+readme.md)
- [ [unsiged char] ](https://stackoverflow.com/questions/75191/what-is-an-unsigned-char)
- [ [>> in numbers] ](http://www.cplusplus.com/forum/beginner/95670/)
- [ [unsiged char propieties] ](https://www.geeksforgeeks.org/maximum-value-of-unsigned-char-in-c/)
- [ [differences between #include "..." and include<...>] ](https://stackoverflow.com/questions/21593/what-is-the-difference-between-include-filename-and-include-filename)
- [ [implement our own Vector Class in C++] ](https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/)
- [ [create bitmap in c++] ](https://www.youtube.com/watch?v=vqT5j38bWGg)
- [ [iniatlize private static atribute] ](https://localcoder.org/error-iso-c-forbids-in-class-initialization-of-non-const-static-member)
- [ [What is "->" after function declaration?] ](https://stackoverflow.com/questions/12417197/what-is-after-function-declaration)
- [ [get current dir] ](https://www.delftstack.com/howto/cpp/get-current-directory-cpp/)
- [ [glog use 1] ](https://codeyarns.com/tech/2017-10-26-how-to-install-and-use-glog.html)
- [ [glog use 2] ](https://rpg.ifi.uzh.ch/docs/glog.html#:~:text=Google%20glog%20defines%20a%20series,verbose%20logging%20levels%2C%20and%20more.)
- [ [glog use 3] ](https://programming.vip/docs/basic-usage-of-glog.html)
- [ [under cursor widget qt] ](https://stackoverflow.com/questions/27363267/get-all-widgets-under-cursor)
- [ [number to string in c++] ](https://www.simplilearn.com/tutorials/cpp-tutorial/int-to-string-cpp#:~:text=The%20next%20method%20in%20this,data%20type%20into%20a%20string.&text=The%20to_string()%20method%20is,string%3E%20or%20.)
- [ [copy directories before cmake buil]](https://stackoverflow.com/questions/13429656/how-to-copy-contents-of-a-directory-into-build-directory-after-make-with-cmake)
- [ [create bin directory with cmake] ](https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir)