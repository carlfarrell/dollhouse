
int WID = 400;
int HEI = 500;
int COLS = 3;
int ROWS = 3;
float colStep, rowStep;
SuperCell[][] cellPop;
int hrct = 1;


void setup() {
  background(0);
  size(WID, HEI);
  frameRate(1);  
  rectMode(CENTER);

  cellPop = new SuperCell[COLS][ROWS];    
  makeCells();
}


void draw() {
  background(0);
  hrct ++;
  if (hrct > 24) hrct = 1;
  println(hrct);
  
  pushMatrix();
  fill(255);
  textSize(14);
  text(hrct + ":00", WID-45, HEI-10);
  popMatrix();
  
  
  //----------------------------------------- RUN CELLS
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      cellPop[i][j].render();
    }
  }
  //----------------------------------------- check cells
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      cellPop[i][j].updateCell();
    }
  }
  //----------------------------------------- toggle cell states
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      cellPop[i][j].toggleCellState();
    }
  }
  //----------------------------------------- print cells
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      println(i + " " + j + " " + cellPop[i][j].getCurrentState());
    }
  }
}


void makeCells() {
  boolean blnSwitch;
  colStep = float(WID)/COLS; 
  rowStep = float(HEI)/ROWS;
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {     
      blnSwitch = true;  
      cellPop[i][j] = new SuperCell( str(i) + "_" + str(j), blnSwitch, new PVector( (colStep/2) + colStep*i, (rowStep/2) + rowStep*j ), colStep, rowStep, i, j );
    }
  }
}

