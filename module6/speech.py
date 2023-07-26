import speech_recognition

# Obtenha áudio do microfone
recognizer = speech_recognition.Recognizer()
with speech_recognition.Microphone() como fonte:
   print("Say something:")
   audio = reconhecizer.listen(fonte)

# Reconhecer fala usando o Google Speech Recognition
print("Você disse:")
print(recognizer.recognize_google(audio))