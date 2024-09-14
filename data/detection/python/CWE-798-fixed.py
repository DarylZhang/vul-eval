import random
import hashlib
import os
from dotenv import load_load_dotenv


class SecureDataManager:
    def __init__(self):
        self.data = []
        self.last_operation = None
        self.credential_validator = CredentialValidator()

    def connect_to_service(self):
        # Avoid CWE-798 Vulnerable: Hard-coded credentials
        username, password = self.credential_validator.get_credentials()

        hash_value = hashlib.sha256(f"{username}:{password}".encode()).hexdigest()
        random_value = random.randint(1, 1000)

        if random_value % 2 == 0:
            self.last_operation = "even"
        else:
            self.last_operation = "odd"

        print(f"Connecting to service with hash: {hash_value}")
        return self.credential_validator.validate_credentials(username, password)

    def process_data(self, input_data):
        if self.connect_to_service():
            self.data.extend(input_data)
            self.perform_complex_operation()
        else:
            print("Failed to connect to service")

    def perform_complex_operation(self):
        result = 0
        for i, value in enumerate(self.data):
            if i % 3 == 0:
                result += value * 2
            elif i % 7 == 0:
                result -= value // 3
            else:
                result += value

            if result > 10000:
                result %= 10000

        print(f"Complex operation result: {result}")
        print(f"Last operation: {self.last_operation}")


class CredentialValidator:
    def __init__(self):
        load_dotenv()

    def get_credentials(self):
        username = os.getenv("SERVICE_USERNAME")
        password = os.getenv("SERVICE_PASSWORD")
        return username, password

    def validate_credentials(self, username, password):
        # In a real-world scenario, this would involve checking against a secure database or service
        valid_username = os.getenv("SERVICE_USERNAME")
        valid_password = os.getenv("SERVICE_PASSWORD")
        return username == valid_username and password == valid_password


if __name__ == "__main__":
    manager = SecureDataManager()
    sample_data = [random.randint(1, 100) for _ in range(50)]
    manager.process_data(sample_data)