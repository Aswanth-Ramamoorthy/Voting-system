# Installation

## Supported Platforms:

Unix, Cygwin and MacOS.

## Prerequisite

GCC Compiler, GNU make, download utilities such as wget or curl.
If using Cygwin, dos2unix will be required

## Dependency Library

To run the project, you have to install the [GSL](https://www.gnu.org/software/gsl/doc/html/index.html#) library

Note that during the installation, GSL will be installed in `lib` directory. To start automatically install process, please the follwing command:

```
./install.sh
```

Please note that if the following errors are seen:
```
./install.sh: line 2: $'\r': command not found
./install.sh: line 5: $'\r': command not found
./install.sh: line 6: cd: $'./lib/\r': No such file or directory
./install.sh: line 7: $'\r': command not found
./install.sh: line 61: syntax error near unexpected token `$'in\r''
'/install.sh: line 61: `case "$(uname -s)" in
```

The following will need to be executed:

```
dos2unix install.sh
./install.sh
```

Execute below command to append GSL library into PATH environment:

```
source ~/.bashrc
```

## Build Project:

```
make
```

Excutable binary sensorfusion file will be placed at `bin` directory.
