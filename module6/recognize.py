# Encontre rostos na imagem
# https://github.com/ageitgey/face_recognition/blob/master/examples/find_faces_in_picture.py
from PIL import Image
import face_recognition

# Carregue o arquivo jpg em uma matriz numpy
image = face_recognition.load_image_file("office.jpg")

# Encontre todos os rostos na imagem usando o modelo baseado em HOG padrão.
# Este método é bastante preciso, mas não tão preciso quanto o modelo CNN e não é acelerado por GPU.
# Veja também: find_faces_in_picture_cnn.py
face_locations = face_recognition.face_locations(image)

for face_location in face_locations:
   # Imprima a localização de cada rosto nesta imagem: cima, direita, baixo, esquerda
   top, right, bottom, left = face_location

   # Você pode acessar o próprio rosto desta forma:
   face_image = image [top: bottom, left: right]
   pil_image = Image.fromarray(face_image)
   pil_image.show()