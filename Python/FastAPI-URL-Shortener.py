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

