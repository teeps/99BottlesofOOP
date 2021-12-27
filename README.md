# 99BottlesofOOP
Coding along with Sandi Metz's book, 99 Bottles of OOP
I'm doing this in C++, and I'd got as far as the end of chapter 4 before creating this repository, so if you're looking for earlier steps this probably won't help.  I'm using Catch2 as the test framework.

\version 0.01 First commit, already coded as far as the end of chapter 4
\version 0.02 Added BottleNumber class (chapter 5)
\version 0.03 Experimented with Capitaliser class of iostream, ultimately abandoned.
\version 0.04 Removed Data Clumps, made successor return a new BottleNumber.  Up to Chapter 6.2
\version 0.05 Implemented BottleNumber Factory
\version 0.06 Moved Factory within BottleNumber class
\version 0.07 Removed the conditional from Factory and made it a singleton to avoid issues with static variable initialisation order.  
Split classes to separate files. 
\version 0.08 Resolved question of how and where to initialise the factory with least ugliness.  This is now performed in BottleNumberFactory.cpp,
so all the application specific initialisation of the factory is in the one place at the top of that file.  Rather than being hard-coded, the factory method 
is now given to the BottleNumber class via a static function pointer, so the BottleNumber class is no longer dependent on that factory class, rather it has 
dependency injection.  The setting up of that function pointer is also handled in BottleNumberFactory.cpp, so there is no code within BottleNumber.h or cpp
other than the code directly required for that class. 
\version 0.09 Corrected some code comments. Modified to deal with the 'law of demeter' violation, although I don't agree that this made things any better!

