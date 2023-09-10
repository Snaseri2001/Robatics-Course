
|  Introduction to Robotics |  Ferdowsi University of Mashhad |
|---|---|
|  Instructor: Arash Sal Moslehian |  Computer Engineering Dept. |

# Getting to know the basic concepts

Read the instructions below and proceed step by step.

-   [Managing Dependencies with rosdep](https://docs.ros.org/en/humble/Tutorials/Intermediate/Rosdep.html)
-   [Using](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Getting-Started-With-Ros2doctor.html)[**ros2doctor**](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Getting-Started-With-Ros2doctor.html)[to identify issues](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Getting-Started-With-Ros2doctor.html)
-   [Writing a simple service and client (C++)](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Cpp-Service-And-Client.html)
-   [Writing a simple service and client (Python)](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Service-And-Client.html) -   [Creating custom msg and srv files](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html)
-   [Implementing custom interfaces](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Single-Package-Define-And-Use-Interface.html)
-   [Using parameters in a class (C++)](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Using-Parameters-In-A-Class-CPP.html)
-   [Using parameters in a class (Python)](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Using-Parameters-In-A-Class-Python.html)
-   [Creating an action](https://docs.ros.org/en/humble/Tutorials/Intermediate/Creating-an-Action.html)
-   [Writing an action server and client (C++)](https://docs.ros.org/en/humble/Tutorials/Intermediate/Writing-an-Action-Server-Client/Cpp.html)
-   [Writing an action server and client (Python)](https://docs.ros.org/en/humble/Tutorials/Intermediate/Writing-an-Action-Server-Client/Py.html)

After reading *all* of the above, do the exercises.

# Exercise 1

1) What is the difference between the packages in [rosdistro/rosdep/base.yaml](https://github.com/ros/rosdistro/blob/master/rosdep/base.yaml) and those that are located in [rosdistro/humble/distribution.yaml](https://github.com/ros/rosdistro/blob/master/humble/distribution.yaml)?
2) According to the previous question, in what category does the `slam_toolbox` package fall and How will rosdep install it? How about the `ffmpeg` package?
3) Briefly explain in one paragraph what IDL is and How ROS uses it. [IDL Spec](https://www.omg.org/spec/IDL/), [ROS IDL Mapping](https://design.ros2.org/articles/idl_interface_definition.html), [rosidl](https://docs.ros.org/en/rolling/Concepts/About-Internal-Interfaces.html#the-rosidl-repository)

# Exercise 2

Yin and Yang want to talk to each other. Create two packages yinsim (Python) and yangsim (C++) which contain yinnode and yangnode respectively.

## Services
Each node has a service. To send a message, in one step, yin sends its message in the role of a client, and in the next step, yang does the same thing. The message sent from the client side to the service contains a string and the length of the string, and the service sends the numerical sum of the characters of the received string in response. (The characters are all ASCII) Each node, upon receiving the other party's message, sends it in the `/conversation` topic using the following format:

```
<name> said: <msg>, <length>, <checksum>
```

Sends where \<name\> is the name of the opposite node, \<msg\> is the message received from the opposite node, \<length\> is the length of the message and \<checksum\> is the numerical sum of the characters of the received string. The whole message is of string type.

## Results 
The answer of the first question is [here.]([https://github.com/Snaseri2001/Robatics-Course/blob/main/Assignmnet1/assinment1.pdf](https://github.com/Snaseri2001/Robatics-Course/blob/main/Assignmnet2/9812762758_Soroush_Naseri_HW2-2.pdf)https://github.com/Snaseri2001/Robatics-Course/blob/main/Assignmnet2/9812762758_Soroush_Naseri_HW2-2.pdf) .
