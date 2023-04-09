from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import random
import string

# Class für URL
class ShortenURL(BaseModel):
    url : str

# Pseudodatenbank
url = []

# erforderliche Funktionen
def gen_key(amount: int) -> str:
    return ''.join(random.choice(string.ascii_letters+string.digits) for _ in range(amount))

# api
app = FastAPI()
short = "http://short.est/"

@app.post("/encode")
def encode(input_url: ShortenURL):
    print(input_url.url)
    # Überprüfe ob URL schon eine gekürzte URL hat
    for x in url:
        if x["url"] == input_url.url:
            return["short_url"]
    # Speichere gekürzte URL in Pseudodatenbank
    output = input_url.dict()
    short_url = short + gen_key(6)
    output.update({"short_url": short_url})
    url.append(output)
    return {"short_url": short_url}

@app.get("/decode")
# gekürzte URL als Übergabeparameter
def decode(short_url: str):
    # Überprüfe: kann gekürzte URL auf Ursprungsurl zurückgeführt werden
    for x in url:
        if x["short_url"] == short_url:
            return {
                "short_url": short_url,
                "url": x["url"]
            }
    raise HTTPException(status_code=404, detail="URL nicht vorhanden")
