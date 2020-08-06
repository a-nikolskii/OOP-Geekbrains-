#include <iostream>
#include <array>
#include <utility>

const int HEIGHT = 10;
const int WIDTH = 10;

class Robot;
struct Point{
    int Y;
    int X;
};

class Grid{
private:
	std::array<std::array <const char*, WIDTH>, HEIGHT> m_grid;
    Point m_position;
	const char* m_empty_cell = " - ";
	const char* m_occupied_cell = " X ";

public:
	Grid(){
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; j++) {
				m_grid[i][j] = m_empty_cell;
			}
		}
		m_position.Y = HEIGHT / 2 - 1;
		m_position.X = WIDTH / 2 - 1;
        set_position(m_position);
	}

	
    Grid(const Point& point)  {
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; j++) {
				m_grid[i][j] = m_empty_cell;
			}
		}
		
		set_position(point);
	}
    
	Grid(const int& x1, const int x2) {
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; j++) {
				m_grid[i][j] = m_empty_cell;
			}
		}
		set_position(x1, x2);
	}

	void Print() {
		system("clear");
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; j++) {
				std::cout << m_grid[i][j];
			}
			std::cout << std::endl;
		}
	}

    
	void set_position(const Point& point) {
		if (point.Y < 0 || point.Y >= HEIGHT){
		    std::string error = "Error: Height must be in range [0.." + std::to_string(HEIGHT - 1) + "]";
			throw error;
		}
		if (point.X < 0 || point.X >= WIDTH) {
		    std::string error = "Error: Width must be in range [0.." + std::to_string(WIDTH - 1) + "]";
			throw error;
		}
        m_grid[m_position.Y][m_position.X] = m_empty_cell;
		m_position = point;
		m_grid[m_position.Y][m_position.X] = m_occupied_cell;
	}
     
	void set_position(const int& x1, const int& x2) {
		if (x1 < 0 || x1 >= HEIGHT){
		    std::string error = "Error: Height must be in range [0.." + std::to_string(HEIGHT - 1) + "]";
			throw error;
		}
		if (x2 < 0 || x2 >= WIDTH) {
		    std::string error = "Error: Width must be in range [0.." + std::to_string(WIDTH - 1) + "]";
			throw error;
		}
        m_grid[m_position.Y][m_position.X] = m_empty_cell;
		m_position.X = x2;
        m_position.Y = x1;
		m_grid[m_position.Y][m_position.Y] = m_occupied_cell;
	}

	Point get_position(){
		return m_position;
	}


};


class Robot {
private:
	Grid m_grid;

	void move_up(){
		Point current_position = m_grid.get_position();
		if (current_position.Y == 0) {
			throw std::string("Going outside the grid. Move_up is not available.\n");
		}
		else {
			current_position.Y -= 1;
			m_grid.set_position(current_position);
		}
	}

	void move_down(){
		Point current_position = m_grid.get_position();
		if (current_position.Y == HEIGHT-1) {
			throw std::string("Going outside the grid. Move_down is not available.\n");
		}
		else {
			current_position.Y += 1;
			m_grid.set_position(current_position);
		}
	}

	void move_left(){
		Point current_position = m_grid.get_position();
		if (current_position.X == 0) {
			throw std::string("Going outside the grid. Move_left is not available.\n");
		}
		else {
			current_position.X -= 1;
			m_grid.set_position(current_position);
		}
	}

	void move_right(){
		Point current_position = m_grid.get_position();
		if (current_position.X == WIDTH-1) {
			throw std::string("Going outside the grid. Move_right is not available.\n");
		}
		else {
			current_position.X += 1;
			m_grid.set_position(current_position);
		}
	}

public:
	void move(std::string command) {
		
		if (command == "up") {
			move_up();
		}
		if (command == "down") {
			move_down();
		}
		if (command == "left") {
			move_left();
		}
		if (command == "right") {
			move_right();
		}
	}

    void Print() {
        m_grid.Print();
    }
};

int main() {
	
	Robot robot;
	std::string command = "";
	std::string error = "\n";

	do {
		robot.Print();
		std::cout << error;
		std::cout << "comand > ";
		std::cin >> command;
		error = "\n";
		try {
		    robot.move(command);
		}
		catch (std::string& ex) {
		    error = ex;
		}
	} while (true);
	return 0;
}