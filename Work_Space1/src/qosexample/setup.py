from setuptools import setup

package_name = 'qosexample'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='soroush',
    maintainer_email='soroush@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'talker_qos=    publishe_qos.talker_qos:mian'
        'listener_qos= subscriber_qos.listener_qos:main'
        ],
    },
)
