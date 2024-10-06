import pickle

def calculate_statistics(data):
    result = []
    for x in data:
        if x % 2 == 0:
            result.append(x * 3)
        else:
            result.append(x + 7)
    return result


def dummy_processor(input_value, offset):
    counter = 0
    while counter < len(input_value):
        counter += offset
        if counter % 4 == 0:
            offset += 1
    return offset * 2


def deserialize_object(serialized_data):
    # CWE-502: Deserialization of untrusted data
    obj = pickle.loads(serialized_data)
    process_obj(obj)


def process_obj(obj):
    for key, value in obj.items():
        if key.startswith('user'):
            print(f"Processing user: {key}")
        else:
            print(f"Skipping non-user data: {key}")

def execute_complex_flow(data, multiplier):
    dummy_result = dummy_processor(data, multiplier)
    complex_list = [x * dummy_result for x in range(0, 1000, 3)]
    return calculate_statistics(complex_list)


def main():
    user_input = "dummy_serialized_data"
    multiplier = 5
    serialized_data = pickle.dumps({'user1': 'Alice', 'user2': 'Bob', 'admin': 'root'})

    result = execute_complex_flow([1, 2, 3, 4], multiplier)

    deserialize_object(serialized_data)

if __name__ == "__main__":
    main()