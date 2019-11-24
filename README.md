# OpenDDS Noob Guide 

1) [Setup](#setup)
2) [First Test](#try)
3) [Support Materials](#materials)


## Setup <a name="setup"></a>

Version : OpenDDS 3.13.3

**1)** OpenDDS compilation:
~~~sh
$ cd OpenDDS -3.13.3
$ ./configure --prefix=usr
~~~

**2)** Set environment and check if it was successful : <a name="environment"></a>
~~~sh
$ source setenv.sh
$ echo $DDS_ROOT
~~~

**3)** Run the entire OpenDDS regression test suite: 
~~~sh
$ bin/auto_run_tests.pl
~~~

**4)** Installation: 
~~~sh
$ make
$ make install
~~~

**IMPORTANT** : 

- whenever a new terminal is used, always set the environment (step 2)
- when reconfiguring, alway clean specific variables by running the commands:
~~~
$ export TAO_ROOT="";
$ export ACE_ROOT="";
$ export MPC_ROOT="";
~~~

-----------------------------------

## First Test <a name="try"></a>
Now that everything is setup and all the OpenDDS tests work, we can try to create the first publisher-subscriber connection. 

**1)** In OpenDDS-3.13.3/DevGuideExamples/DCPS/Messenger, run: 
~~~sh
$ tao_idl Messenger.idl
$ opendds_idl Messenger.idl
~~~
This allows to generate *MessengerTypeSupport.idl*, *MessengerTypeSupportImpl.h* and *MessengerTypeSupportImpl.cpp*.

**2)** Initiate Broker
First we will start a DCPSInfoRepo service so our publishers and subscribers can fnd one another.
~~~sh
$DDS_ROOT/bin/DCPSInfoRepo -o simple.ior
~~~

**3)** Initiate Publisher
The publisher connects to the DCPSInfoRepo to fnd the location of any subscribers and begins to publish messages as well as write them to the console.

- **Open new terminal window**
- [set environment](#environment) 
~~~sh
$ ./publisher -DCPSInfoRepo file://simple.ior
~~~

**4)** Initiate Subscriber
Start the subscriber application:

- **Open new terminal window**
- [set environment](#environment) 
~~~sh
$ ./subscriber -DCPSInfoRepo file://simple.ior
~~~

-----------------------------------

## Support Materials <a name="materials"></a>

- [OpenDDS documentation](https://opendds.org/)
- [OpenDDS Developer's Guide](http://download.objectcomputing.com/OpenDDS/OpenDDS-latest.pdf)
- [objectcomputing/OpenDDS (Github repo)](https://github.com/objectcomputing/OpenDDS)

