import time

def dummy_func_one(x):
    res = 0
    if x > 10000:
        x = 10000
    for i in range(x):
        res += i * x - i
    return res

def dummy_func_two(lst):
    return [x * 2 for x in lst]

def dummy_func_three(data):
    processed_data = []
    for chunk in data:
        if len(chunk) > 100:
            chunk = chunk[:100]
        processed_data.append(chunk[::-1])
    return processed_data

def resource_consuming_task(file_path, data_limit):
    data_store = []
    with open(file_path, 'r') as file:
        while True:
            data = file.read(data_limit)
            if not data:
                break
            data_store.append(data)
            dummy_func_one(len(data))
            dummy_func_two([1, 2, 3])
            dummy_func_three(data_store)
    return data_store

def main():
    path_to_file = "dummy_large_file.txt"
    limit = 4096
    final_data = resource_consuming_task(path_to_file, limit)
    time.sleep(2)
    print("Data processing complete.")

if __name__ == "__main__":
    main()