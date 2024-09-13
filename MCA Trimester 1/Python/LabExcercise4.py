from abc import ABC, abstractmethod

class SentimentAnalyzer(ABC):
    @abstractmethod
    def analyze(self, data):
        pass

class TextSentimentAnalyzer(SentimentAnalyzer):
    def analyze(self, data):
        return f"Text sentiment analysis result for '{data}': Positive"

class ImageSentimentAnalyzer(SentimentAnalyzer):
    def analyze(self, data):
        return f"Image sentiment analysis result for '{data}': Neutral"

class AudioSentimentAnalyzer(SentimentAnalyzer):
    def analyze(self, data):
        return f"Audio sentiment analysis result for '{data}': Negative"
    
analyzers = [
    TextSentimentAnalyzer(),
    ImageSentimentAnalyzer(),
    AudioSentimentAnalyzer()
] 

data_samples = [
    "I love programming!",
    "happy_face.jpg",
    "excited_voice.wav"
]

for analyzer, data in zip(analyzers, data_samples):
    print(analyzer.analyze(data))