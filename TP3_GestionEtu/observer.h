#pragma once


/**
 * @brief Class to manage the observer, the dynamic element from the application
*/


class Observer {
public:
  virtual ~Observer() {}
  virtual void update() = 0;


};


/**
 * @brief Class to manage the observable, 
*/

class Observable {
public:
  virtual ~Observable() {}
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObserver() = 0;
};
