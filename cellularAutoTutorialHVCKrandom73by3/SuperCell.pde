
class SuperCell {

  PVector pos;
  float sizeXX, sizeYY;
  boolean currState, nextState;
  int cellCol, indexI, indexJ;
  String myID;
  boolean atwork = false;
  int workshift = 0;


  SuperCell( String _ID, boolean _S, PVector _P, float _SX, float _SY, int _II, int _JJ ) {

    pos        = _P;
    indexI     = _II;  
    indexJ     = _JJ;
    myID       = _ID;
    currState  = _S;

    sizeXX     = _SX;
    sizeYY     = _SY;
    cellCol    = 250;
  }


  //------------------------------------ draw the cell
  void render() {
    if ( this.getCurrentState() ) {
      stroke(cellCol, cellCol, 0);
      fill(cellCol, cellCol, 0, 95);
      ellipse(pos.x, pos.y, sizeXX/3, sizeYY/3);
    }
    else {      
      stroke(cellCol/5, cellCol/5, cellCol/5);
      fill(cellCol, cellCol, cellCol, 70); 
      ellipse(pos.x, pos.y, sizeXX/6, sizeYY/6);
    }
  }

  //------------------------------------ update current state to the next state
  void updateCell() {
    this.applyRules();
  }

  //------------------------------------ apply rules of life
  void applyRules() {


    //----------------------------------------- top floor
    if ( indexJ == 0  ) {
      float LIKE = .3;
      if (random(1) < LIKE) if ( hrct > random(6, 13) && hrct < random(21, 24)) setNextState(true);
      else setNextState(false);
    }

    //----------------------------------------- middle floor
    if ( indexJ ==  1 ) {
      float LIKE = .9;
      if (atwork == true) {
        if (workshift >= 1 && workshift < 8) workshift++;
        else if (workshift >= 8) {
          workshift = 0;
          atwork = false;
        }
      }
      if (random(1) < LIKE) if ( hrct == 8) { 
        atwork = true;
        workshift = 1;
      }
      if (random(1) < LIKE) if ( hrct > random(4, 6) && hrct < 8) setNextState(true);
      if (random(1) < LIKE) if ( hrct > random(16, 20) && hrct < random(20, 23)) setNextState(true);
      else setNextState(false);
    }

    //----------------------------------------- bottom floor
    if ( indexJ == 2  ) {
      float LIKE = .6;
      if (atwork == true) {
        if (workshift >= 1 && workshift < 8) workshift++;
        else if (workshift >= 8) {
          workshift = 0;
          atwork = false;
        }
      }
      if (random(1) < LIKE) if ( hrct == 15) { 
        atwork = true;
        workshift = 1;
      }
      if (random(1) < LIKE) if ( hrct > random(7, 13) && hrct < 15) setNextState(true);
      if (random(1) < LIKE) if ( hrct > random(22, 24)) setNextState(true);
      if (random(1) < LIKE) if ( hrct < random(0, 4)) setNextState(true);
      else setNextState(false);
    }
    
  }

  //------------------------------------ toggle cell state
  void toggleCellState() {
    boolean bVal = nextState;
    currState = bVal;
    //setCurrentState(bVal);
  }

  //------------------------------------ set cell states
  void setCurrentState(boolean B) {
    currState = B;
  }
  void setNextState(boolean B) {
    nextState = B;
  }

  //------------------------------------ retrieve cell states
  boolean getCurrentState() {
    return currState;
  }  
  boolean getNextState() {
    return nextState;
  }
}

