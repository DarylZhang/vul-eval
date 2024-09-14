import random
import hashlib


class DataManager:
    def __init__(self):
        self.data = []
        self.last_operation = None

    def connect_to_service(self):
        # CWE-798 Vulnerable: Hard-coded credentials
        username = "admin"
        password = "super_secret_password"

        hash_value = hashlib.sha256(f"{username}:{password}".encode()).hexdigest()
        random_value = random.randint(1, 1000)

        if random_value % 2 == 0:
            self.last_operation = "even"
        else:
            self.last_operation = "odd"

        print(f"Connecting to service with hash: {hash_value}")
        return True

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


if __name__ == "__main__":
    manager = DataManager()
    sample_data = [random.randint(1, 100) for _ in range(50)]
    manager.process_data(sample_data)