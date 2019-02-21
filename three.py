
import requests
# from pprint import pprint


def retrieveJobLinks():
    jobs = requests.get("https://indiana.dejobs.org/jobs/feed/json?num_items=10").json()
    return [job["url"] for job in jobs]


# if __name__ == "__main__":
#     pprint(retrieveJobLinks())
