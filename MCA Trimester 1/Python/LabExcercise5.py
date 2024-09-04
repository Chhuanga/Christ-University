from abc import ABC, abstractmethod

class DataAnalyzer(ABC):
    @abstractmethod
    def analyze(self, data):
        pass

class AnalysisError(Exception):
    pass

class TextDataAnalyzer(DataAnalyzer):
    def analyze(self, data):
        try:
            if not isinstance(data, str):
                raise TypeError("Data must be a string")
            if len(data) == 0:
                raise ValueError("Data cannot be empty")
 
            return f"Text analysis result for '{data}': Positive"
        except (TypeError, ValueError) as e:
            print(f"Error analyzing text data: {e}")
        except Exception as e:
            print(f"Unexpected error: {e}")
            raise AnalysisError("An error occurred during text analysis")

class NumericDataAnalyzer(DataAnalyzer):
    def analyze(self, data):
        try:
            if not isinstance(data, (int, float)):
                raise TypeError("Data must be a number")
            if data < 0:
                raise ValueError("Data must be non-negative")
            return f"Numeric analysis result for '{data}': Valid" 
        except (TypeError, ValueError) as e:
            print(f"Error analyzing numeric data: {e}")
        except Exception as e:
            print(f"Unexpected error: {e}")
            raise AnalysisError("An error occurred during numeric analysis")

analyzers = [
    TextDataAnalyzer(),
    NumericDataAnalyzer()
]

data_samples = [
    "I love programming!",
    42,
    "",
    -5,
    3.14,
    None
]

for analyzer in analyzers:
    for data in data_samples:
        result = analyzer.analyze(data)
        if result:
            print(result)

