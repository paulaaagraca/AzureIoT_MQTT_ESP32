# OpenDDS Noob Guide 

1) [Setup](#setup)
2) [First trial](#try)


## Setup <a name="setup"></a>

Version : OpenDDS 3.13.3

**1)** OpenDDS compilation:
~~~
$ cd OpenDDS -3.13.3
$ ./configure --prefix=usr
~~~

**2)** Set environment and check if it was successful : 
~~~
$ source setenv.sh
$ echo $DDS_ROOT
~~~

**3)** Run the entire OpenDDS regression test suite: 
~~~console
foo:$ bin/auto_run_tests.pl
~~~

**4)** Installation: 
~~~
$ make
$ make install
~~~
-----------------------------------
**IMPORTANT** : 

- whenever a new terminal is used, always set the environment (step 2)
- when reconfiguring, alway clean specific variables by running the commands:
~~~
$ export TAO_ROOT="";
$ export ACE_ROOT="";
$ export MPC_ROOT="";
~~~

## First trial <a name="try"></a>
Now that everything is setup and all the OpenDDS tests work, we can try to create the first publisher-subscriber connection.

