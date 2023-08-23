#include <iostream>
#include <limits>
#include <cmath>
#include <vector>


class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};


class Max : public IStatistics {
public:
	Max() : m_max{-std::numeric_limits<double>::max()} {}


	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char* name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	Mean() : sum_{0}, count_{0} {}

	void update(double val) override {
		sum_ += val;
		++count_;
	}

	double eval() const override {
		if (count_ == 0) return 0;
		return sum_ / count_;
	}

	const char* name() const override {
		return "arithmetic mean";
	}

private:
	double sum_;
	size_t count_;	    // TODO подозреваю что так делать опасно, 
					// поскольку в момент деления будет преобразование типа в double, 
					// зато защита от 1.5 землекопа
};

class StdDeviation : public IStatistics {
	public:
		StdDeviation() : count_{0}, sum_{0} {}

		void update(double val) override {
			numbers_.push_back(val);
			sum_ += val;
			++count_;
		}

		double eval() const override {
			if (count_ == 0) return 0;

			double mean = sum_ / count_;
			double s = 0;
			for (double number : numbers_) {
				s += pow(number - mean, 2);
			}
			return sqrt(s / count_);
		}

		const char* name() const override {
			return "standard deviation";
		}

	private:
		std::vector<double> numbers_;
		double sum_;
		size_t count_;
};

int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new StdDeviation{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}