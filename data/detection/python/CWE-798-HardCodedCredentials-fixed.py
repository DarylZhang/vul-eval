import os

def complex_helper_1(a, b):
    if a > b:
        return b + (a * 2)
    else:
        return a + (b / 2)

def complex_helper_2(data):
    for i in range(len(data)):
        data[i] = (data[i] * 3) + 1
    return data

def dummy_logic(x, y, z):
    result = complex_helper_1(x, y)
    if z > result:
        result += complex_helper_2([x, y, z])[0]
    return result

class CredentialsManager:
    def __init__(self, user_name):
        self.user_name = user_name

    def process_data(self, val1, val2):
        result = dummy_logic(val1, val2, len(self.user_name))
        return result

    def connect_to_service(self, service_url):
        password = os.getenv('SERVICE_PASSWORD')
        connection_string = f"{service_url}?user={self.user_name}&password={password}"
        if len(service_url) > 10:
            result = complex_helper_2([len(service_url), len(self.user_name)])
        else:
            result = complex_helper_1(len(service_url), len(self.user_name))
        return connection_string, result

def main():
    user = "admin_user"
    url = "http://example.com/api"
    cm = CredentialsManager(user)
    cm.process_data(5, 10)
    connection_details = cm.connect_to_service(url)
    print(connection_details)

if __name__ == "__main__":
    main()