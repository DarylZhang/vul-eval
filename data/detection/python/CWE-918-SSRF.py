import requests

def dummy_transform_a(data):
    return data[::-1] + "XYZ"

def dummy_logic_1(val):
    res = 0
    for i in range(val):
        res += i ** 2
    return res

def complex_handler(url):
    dummy_result = dummy_transform_a(url)
    num = len(dummy_result) * 5
    dummy_value = dummy_logic_1(num)

    if dummy_value % 2 == 0:
        status = internal_request_handler(url)
    else:
        status = fallback_request_handler(url)

    return status

def internal_request_handler(url):
    dummy_check = url.startswith("http")
    if not dummy_check:
        dummy_value_2 = dummy_logic_2(url)
        return "Invalid URL"
    response = requests.get(url)
    return response.content

def fallback_request_handler(url):
    return "Fallback executed"

def dummy_logic_2(data):
    count = 0
    for i in range(len(data)):
        count += ord(data[i]) % 10
    return count

def main():
    endpoint = "http://internal-service/resource"
    result = complex_handler(endpoint)
    print(result)

if __name__ == "__main__":
    main()