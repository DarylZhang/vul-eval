import html

def dummy_logic_16(data):
    return data[::-1]

def render_web_page(content):
    dummy_logic_16(content)
    content = html.escape(content)
    html_page = f"<html><body>{content}</body></html>"
    return html_page

def dummy_logic_17():
    return 42

def main():
    user_input = input("Enter some content: ")
    result = render_web_page(user_input)
    print(f"Generated HTML: {result}")

if __name__ == "__main__":
    main()