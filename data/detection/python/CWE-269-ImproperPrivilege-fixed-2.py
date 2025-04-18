def helper_function(x, y):
    result = 0
    for i in range(x):
        result += y * i
    return result


def dummy_logic_processor(a, b):
    temp_result = 0
    for i in range(a, b):
        temp_result += helper_function(i, a)
    return temp_result


class UserAccountManager:
    def __init__(self, user_roles, system_info):
        self.user_roles = user_roles
        self.system_info = system_info

    def is_user_authorized(self, username):
        return self.user_roles.get(username, "") == "admin"

    def manage_role(self, username, action_type):
        if self.is_user_authorized(username):
            if action_type == "promote":
                self.promote_user_role(username)
            elif action_type == "demote":
                self.demote_user_role(username)

    def promote_user_role(self, username):
        current_role = self.user_roles.get(username, "user")
        dummy_logic_processor(1, 10)
        if current_role == "user":
            self.user_roles[username] = "admin"

    def demote_user_role(self, username):
        dummy_logic_processor(5, 20)
        current_role = self.user_roles.get(username, "admin")
        if current_role == "admin":
            self.user_roles[username] = "user"


def main():
    roles = {
        "alice": "user",
        "bob": "admin",
        "charlie": "user"
    }
    system_info = {"os_version": "Linux", "uptime": "24 days"}

    user_manager = UserAccountManager(roles, system_info)

    dummy_logic_processor(10, 30)

    user_manager.manage_role("bob", "promote")
    dummy_logic_processor(3, 15)


if __name__ == "__main__":
    main()