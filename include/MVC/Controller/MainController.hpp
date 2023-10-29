//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//    MIT License                                                                       //
//                                                                                      //
//    Copyright (c) 2023 Charels Hugo                                                   //
//                                                                                      //
//    Permission is hereby granted, free of charge, to any person obtaining a copy      //
//    of this software and associated documentation files (the "Software"), to deal     //
//    in the Software without restriction, including without limitation the rights      //
//    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell         //
//    copies of the Software, and to permit persons to whom the Software is             //
//    furnished to do so, subject to the following conditions:                          //
//                                                                                      //
//    The above copyright notice and this permission notice shall be included in all    //
//    copies or substantial portions of the Software.                                   //
//                                                                                      //
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR        //
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,          //
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE       //
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER            //
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,     //
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     //
//    SOFTWARE.                                                                         //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////


// Macro
#pragma once

// C++ Standard Library
#include <unordered_map>
#include <memory>



namespace mvclib
{


// Forward declarations
template<typename StateType, typename EventType>
class AbstractController<StateType, EventType>;



template<typename StateType, typename EventType>
class MainController
{
public:

    // Constructors and destructors
    MainController();

    ~MainController();

    // Methods
    void handle(StateType &state, EventType &event);

    // Modifiers
    void addController(StateType state, AbstractController<StateType, EventType>* controller);

    void removeController(StateType state);

    void clearControllers();


protected:

    std::unordered_map<StateType, std::unique_ptr<AbstractController<StateType, EventType>>> controllers;

    AbstractController<StateType, EventType>* getCurrentController(StateType state);


private:



}; // class MainController


} // namespace mvclib
