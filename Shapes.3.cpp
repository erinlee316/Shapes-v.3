// Assignment 4, Shapes v.3

// Program will read from entire text file and process it line-by-line, parsing
// the shapes and making them as objects, which are stored in a bag for later.
// Objects will be retrieved to call member functions that calculate and output
// the area, perimeter, volume, and surface area of various shapes into two sources.

// c++ libraries
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// c libraries
#include <cstdlib>   // atof
#include <cmath>     // sqrt and M_PI

// structure variables with member functions
// square dimensions
struct Square
{
  double length;
  void calculation(ostream&) const;
};

// rectangle dimensions
struct Rectangle
{
  double length;
  double width;
  void calculation(ostream&) const;
};

// circle dimensions
struct Circle
{
  double radius;
  void calculation(ostream&) const;
};

// triangle dimensions
struct Triangle
{
  double length;
  void calculation(ostream&) const;
};

// cube dimensions
struct Cube
{
  double length;
  void calculation(ostream&) const;
};

// box dimensions
struct Box
{
  double length;
  double width;
  double height;
  void calculation(ostream&) const;
};

// cylinder dimensions
struct Cylinder
{
  double height;
  double radius;
  void calculation(ostream&) const;
};

// prism dimensions
struct Prism
{
  double length;
  double height;
  void calculation(ostream&) const;
};

// function prototypes
void id();
vector<string> parseString(string);
ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);

int main()
{
  // function call for identification information
  id();

  // declare and initialize variables
  ifstream fin;     
  ofstream fout; 
  string line;
  vector<string> tokens;   
  vector<void*> myBag;
  vector<int> myBagType;

  // open files
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  // Check if input file is opened successfully
  if (!fin.good())
  {
    cout << "Input file failed to open." << endl;
    return 1;
  }
 
  // Check if output file is opened successfully
  if (!fout.good())
  {
    cout << "Output file failed to open." << endl;
    return 1;
  }

  // keep looping until end of file is reached
  while (!fin.eof())
  {
    // read each line from input file and call function to get tokens
    getline(fin, line);
    tokens = parseString(line);

    // will skip any empty lines from input file
    if (tokens.size() != 0)
    {
      // check if token is square
      if (tokens[0] == "SQUARE")
      {
        // dynamically allocate memory for a new square object and store in bag
        // store 1 into different bag to represent square shape
        Square* s = new Square;
        myBag.push_back(s);
        myBagType.push_back(1);

        // check if enough tokens for sides
        // if not, assign the side with 0
        s->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
      }

      // check if token is rectangle
      else if (tokens[0] == "RECTANGLE")
      {
        // dynamically allocate memory for a new rectangle object and store in bag
        // store 2 into different bag to represent rectangle shape
        Rectangle* r = new Rectangle;
        myBag.push_back(r);
        myBagType.push_back(2);

        // check if enough tokens for sides
        // if not, assign the side with 0
        r->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        r->width = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
      }

      // check if token is circle
      else if (tokens[0] == "CIRCLE")
      {
        // dynamically allocate memory for a new circle object and store in bag
        // store 3 into different bag to represent circle shape
        Circle* c = new Circle;
        myBag.push_back(c);
        myBagType.push_back(3);

        // check if enough tokens for sides
        // if not, assign the side with 0
        c->radius = (tokens.size() > 1) ?  atof(tokens[1].c_str()) : 0;
      }

      // check if token is triangle
      else if (tokens[0] == "TRIANGLE")
      {
        // dynamically allocate memory for a new triangle object and store in bag
        // store 4 into different bag to represent triangle shape
        Triangle* t = new Triangle;
        myBag.push_back(t);
        myBagType.push_back(4);

        // check if enough tokens for sides
        // if not, assign the side with 0
        t->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
      }

      // check if token is cube
      else if (tokens[0] == "CUBE")
      {
        // dynamically allocate memory for a new cube object and store in bag
        // store 5 into different bag to represent cube shape
        Cube* c = new Cube;
        myBag.push_back(c);
        myBagType.push_back(5);

        // check if enough tokens for sides
        // if not, assign the side with 0
        c->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
      }

      // check if token is box           
      else if (tokens[0] == "BOX")
      {
        // dynamically allocate memory for a new box object and store in bag
        // store 6 into different bag to represent box shape
        Box* b = new Box;
        myBag.push_back(b);
        myBagType.push_back(6);

        // check if enough tokens for sides
        // if not, assign the side with 0
        b->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        b->width = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
        b->height = (tokens.size() > 3) ? atof(tokens[3].c_str()) : 0;
      }

      // check if token is cylinder      
      else if (tokens[0] == "CYLINDER")
      {
        // dynamically allocate memory for a new cylinder object and store in bag
        // store 7 into different bag to represent cylinder shape
        Cylinder* c = new Cylinder;
        myBag.push_back(c);
        myBagType.push_back(7);

        // check if enough tokens for sides
        // if not, assign the side with 0
        c->radius = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        c->height = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
      }

      // check if token is prism
      else if (tokens[0] == "PRISM")
      {
        // dynamically allocate memory for a new prism object and store in bag
        // store 8 into different bag to represent prism shape
        Prism* p = new Prism;
        myBag.push_back(p);
        myBagType.push_back(8);

        // check if enough tokens for sides
        // if not, assign the side with 0
        p->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        p->height = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
      }

      // check if token is EOF      
      else if (tokens[0] == "EOF")
        break;

      // token does not match one of eight objects
      else
        cout << tokens[0] << " invalid object" << endl;
    }
  }

  // close input file
  fin.close();

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert pointer in vector into pointer to square object
        // dereference the pointer to access square object
        // call function to calculate and display info to console output        
        Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
        Square& rSquare = *pSquare;
        rSquare.calculation(cout);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert pointer in vector into pointer to rectangle object
        // dereference the pointer to access rectangle object     
        // call function to calculate and display info to console output        
        Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
        Rectangle& rRectangle = *pRectangle; 
        rRectangle.calculation(cout);
        break;
      }
      // integer 3 represents circle
      case 3:
      {
        // convert pointer in vector into pointer to circle object
        // dereference the pointer to access circle object            
        // call function to calculate and display info to console output        
        Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
        Circle& rCircle = *pCircle;
        rCircle.calculation(cout);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert pointer in vector into pointer to triangle object
        // dereference the pointer to access triangle object           
        // call function to calculate and display info to console output        
        Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
        Triangle& rTriangle = *pTriangle;
        rTriangle.calculation(cout);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert pointer in vector into pointer to cube object
        // dereference the pointer to access cube object            
        // call function to calculate and display info to console output        
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        Cube& rCube = *pCube;
        rCube.calculation(cout);
        break;
      }
      
      // integer 6 represents box
      case 6:
      {
        // convert pointer in vector into pointer to box object
        // dereference the pointer to access box object            
        // call function to calculate and display info to console output        
        Box* pBox = reinterpret_cast<Box*>(myBag[i]);
        Box& rBox = *pBox;
        rBox.calculation(cout);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert pointer in vector into pointer to cylinder object
        // dereference the pointer to access cylinder object           
        // call function to calculate and display info to console output        
        Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
        Cylinder& rCylinder = *pCylinder;
        rCylinder.calculation(cout);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert pointer in vector into pointer to prism object
        // dereference the pointer to access prism object   
        // call function to calculate and display info to console output        
        Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
        Prism& rPrism = *pPrism;
        rPrism.calculation(cout);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert pointer in vector into pointer to square object
        // dereference the pointer to access square object            
        // call function to calculate and display info to file output        
        Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
        Square& rSquare = *pSquare;
        rSquare.calculation(fout);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert pointer in vector into pointer to rectangle object
        // dereference the pointer to access rectangle object            
        // call function to calculate and display info to file output        
        Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
        Rectangle& rRectangle = *pRectangle; 
        rRectangle.calculation(fout);
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert pointer in vector into pointer to circle object
        // dereference the pointer to access circle object            
        // call function to calculate and display info to file output        
        Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
        Circle& rCircle = *pCircle;
        rCircle.calculation(fout);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert pointer in vector into pointer to triangle object
        // dereference the pointer to access triangle object            
        // call function to calculate and display info to file output        
        Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
        Triangle& rTriangle = *pTriangle;
        rTriangle.calculation(fout);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert pointer in vector into pointer to cube object
        // dereference the pointer to access cube object            
        // call function to calculate and display info to file output        
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        Cube& rCube = *pCube;
        rCube.calculation(fout);
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert pointer in vector into pointer to box object
        // dereference the pointer to access box object            
        // call function to calculate and display info to file output        
        Box* pBox = reinterpret_cast<Box*>(myBag[i]);
        Box& rBox = *pBox;
        rBox.calculation(fout);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert pointer in vector into pointer to cylinder object
        // dereference the pointer to access cylinder object            
        // call function to calculate and display info to file output        
        Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
        Cylinder& rCylinder = *pCylinder;
        rCylinder.calculation(fout);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert pointer in vector into pointer to prism object
        // dereference the pointer to access prism object            
        // call function to calculate and display info to file output        
        Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
        Prism& rPrism = *pPrism;
        rPrism.calculation(fout);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert pointer in vector into pointer to square object
        // delete dynamically allocated square object      
        Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
        delete pSquare;
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert pointer in vector into pointer to rectangle object
        // delete dynamically allocated rectangle object   
        Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
        delete pRectangle;
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert pointer in vector into pointer to circle object
        // delete dynamically allocated circle object   
        Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
        delete pCircle;
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert pointer in vector into pointer to triangle object
        // delete dynamically allocated triangle object   
        Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
        delete pTriangle;
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert pointer in vector into pointer to cube object
        // delete dynamically allocated cube object   
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        delete pCube;
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert pointer in vector into pointer to box object
        // delete dynamically allocated box object   
        Box* pBox = reinterpret_cast<Box*>(myBag[i]);
        delete pBox;
        break;
      }
     
      // integer 7 represents cylinder
      case 7:
      {
        // convert pointer in vector into pointer to cylinder object
        // delete dynamically allocated cylinder object   
        Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
        delete pCylinder;
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert pointer in vector into pointer to prism object
        // delete dynamically allocated prism object   
        Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
        delete pPrism;
        break;
      }

      default:
        break;
    }
  }

  // close output file
  fout.close();

  return 0;
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// function will take a string and create an array of tokens
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

// function will round numbers to two decimal digits
ostream& roundingTwo(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

// function will turn off rounding back to default
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

// member function will perform calculations for square and display results 
void Square::calculation(ostream& out) const
{
  // calculate area and perimeter
  double area = length * length;
  double perimeter = 4 * length;

  // display results to console or file
  out << "SQUARE side=" << length;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for rectangle and display results 
void Rectangle::calculation(ostream& out) const
{ 
  // calculate area and perimeter
  double area = length * width;
  double perimeter = 2 * (length + width);

  // display results to console or file
  out << "RECTANGLE length=" << length << " width=" << width;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for circle and display results 
void Circle::calculation(ostream& out) const
{        
  // calculate area and perimeter
  double area = M_PI * radius * radius;
  double perimeter = 2 * M_PI * radius;

  // display results to console or file
  out << "CIRCLE radius=" << radius;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for triangle and display results 
void Triangle::calculation(ostream& out) const
{        
  // calculate area and perimeter
  double area = (sqrt(3) / 4) * length * length;
  double perimeter = 3 * length;

  // display results to console or file
  out << "TRIANGLE side=" << length;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// member function will perform calculations for cube and display results 
void Cube::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = 6 * length * length;
  double volume = length * length * length;

  // display results to console or file
  out << "CUBE side=" << length;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// member function will perform calculations for box and display results 
void Box::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = 2 * ((length * width) + (width * height) + (length * height));
  double volume = length * width * height;

  // display results to console or file
  out << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// member function will perform calculations for cylinder and display results 
void Cylinder::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = (2 * M_PI * radius * radius) + (2 * M_PI * radius * height);
  double volume = M_PI * radius * radius * height;

  // display results to console or file
  out << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// member function will perform calculations for prism and display results 
void Prism::calculation(ostream& out) const
{
  // calculate surface area and volume
  double area = ((sqrt(3) / 2) * length * length) + (3 * length * height);
  double volume = (sqrt(3) / 4) * length * length * height;

  // display results to console or file
  out << "PRISM side=" << length << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}
