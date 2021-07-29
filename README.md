# Storage_media
C++_Storage_media

List of storage media
Design a program that builds a list
storage media such as a USB flash drive,
portable hard disk, DVD-disk. Every carrier
information is an object of the corresponding class:
- class "USB flash drive";
- class "Portable hard drive";
- class "DVD-disc".
All three classes are derived from abstract
base class "Information carrier".
The base class stores the manufacturer's name, model,
name, media capacity, quantity. The class has
all the necessary accessor methods, and
methods of printing, loading and saving. Derivatives
classes override print, load and
conservation. In addition, each of the derived classes
complemented by the following fields:
- class "USB flash drive": USB speed;
- Class "Portable hard drive": rotation speed
spindle;
- class "DVD-disc": recording speed.
Working with objects of the corresponding classes
is made through pointers to the base class, which
stored in a dynamic array.
The program should provide an opportunity
adding, deleting (by number), printing, changing (by
number) of certain media parameters, search by
a given criterion, as well as the ability to load data from
file and save the data to a file.
The "Media Name" field should be used for
identification of the storage medium only at boot
data from the file. In other cases, for identification
the information carrier must use the RTTI mechanism
(dynamic type identification) or polymorphic
casting of types using the dynamic_cast operator.
