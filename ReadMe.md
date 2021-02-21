# C++ Sandbox

This repository is a collection of test and evaluation-projects, that were mostly written during the development of other projects.

In my experience it appeared to be a waste of time to quickly elaborate a certain hack in some particular project and then leave it alone there. I happened to search several times for the background of a certain hack or searched again for the project some hack was implemented to see again the context because I couldn't apply a small code snippet I saved (if was a bit more diligent).

I came to the decision to periodically elaborate different topics and document the results much more carefully than I used to do in small evaluation projects. The results could  be useful as reference or base for small examples or could also happen to be useful in a training. 

The examples target

- Language features of C or C++
- Libraries of C or C++
- Tooling features
  - Compiler tool-chain
  - Other tools for Code processing or documentation

The following sections describe the content so far. Note that it could be necessary to switch to the develop-branch to see stated parts.

## C - Folder

### CuInAssembler

A small projects that is compiled and analyzed by bash script. Main purpose is to learn / introduce gnu tooling and get familiar with output files. 

### For_While

A small test to determine if while is faster then for

### FunctionCalls

A test to show how implementation (inline, in header, in source) an compiler-settings affect compilation.

### MacroMagic

A demonstration of different precompiler-features, but the macro function in particular. This also covers the Stringify and Combine feature.

### UsingPrintF

A demonstration of the printf function from standard library. 

## Cpp - Folder



### ClassImplementation

A test on a demo class to show how implementation (inline, in header, in source) an compiler-settings affect compilation.

### CSharpLikeProperty

A demonstration of templates to enable C# like Property access with `Obj.X` rather than `Obj.GetX()`.

### UsingReferences

A demonstration of the Reference-operator `&` in different use cases.



## CMake

### DemoProject

A small CMake project covering different types of libraries and tests.

