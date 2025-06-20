FROM continuumio/anaconda3

WORKDIR /app

COPY . /app

# Instalacja zależności, jeśli istnieje requirements.txt
RUN if [ -f requirements.txt ]; then pip install --no-cache-dir -r requirements.txt; fi

CMD [ "bash" ]